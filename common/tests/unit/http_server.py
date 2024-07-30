from flask import Flask, request, jsonify

app = Flask(__name__)

# In-memory storage for fruits
fruits = {}

@app.route('/')
def home():
    return 'Welcome to the Flask server!'

@app.route('/api/get', methods=['GET'])
def get_message():
    return jsonify({'message': 'GET request received'})

@app.route('/api/post', methods=['POST'])
def post_message():
    data = request.get_json()
    if not data or 'fruit' not in data:
        return jsonify({'error': 'No fruit data received'}), 400
    
    fruit_name = data['fruit']
    fruits[fruit_name] = data
    
    return jsonify({'message': 'POST request received', 'data': data})

@app.route('/api/fruits', methods=['GET'])
def get_fruits():
    return jsonify(fruits)

@app.route('/api/another', methods=['GET'])
def another_endpoint():
    return jsonify({'message': 'This is another GET endpoint'})

if __name__ == '__main__':
    print("Hi")
    app.run(host='127.0.0.1', port=8080, debug=True)
