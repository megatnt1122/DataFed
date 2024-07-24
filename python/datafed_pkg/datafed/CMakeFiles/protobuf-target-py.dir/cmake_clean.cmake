file(REMOVE_RECURSE
  "SDMS_Anon_pb2.py"
  "SDMS_Auth_pb2.py"
  "SDMS_pb2.py"
  "Version_pb2.py"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/protobuf-target-py.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
