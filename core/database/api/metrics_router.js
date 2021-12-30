'use strict';

const   createRouter = require('@arangodb/foxx/router');
const   router = createRouter();
const   g_db = require('@arangodb').db;
const   g_lib = require('./support');
const   joi = require('joi');

module.exports = router;

router.post('/msg_count/update', function (req, res) {
    try {
        var i,u,
            ts = req.body.timestamp,
            obj = {timestamp:ts,type:"msgcnt_total",total:req.body.total};

        g_db.metrics.save( obj );

        for ( i in req.body.uids ){
            u = req.body.uids[i];
            obj = {timestamp:ts,type:"msgcnt_user",uid:i,total:u.tot,msg:u.msg};
            g_db.metrics.save( obj );
        }
    } catch( e ) {
        g_lib.handleException( e, res );
    }
})
.body( joi.object().required(), 'Metrics')
.summary('Update message metrics.')
.description('Update message metrics.');

router.get('/msg_count', function (req, res) {
    try {
        var par = { now: Date.now()/1000, since: 60*( req.queryParams.since?req.queryParams.since:60 )},
            filter = "(( i.timestamp + @since ) >= @now )";

        if ( req.queryParams.type ){
            filter += " && i.type == @type"
            par.type = req.queryParams.type;
        }

        if ( req.queryParams.uid ){
            filter += " && i.uid == @uid"
            par.uid = req.queryParams.uid;
        }

        var qry = "for i in metrics filter " + filter + " sort i.timestamp return i",
            result = g_db._query( qry, par ).toArray(),
            r;

        for ( var i in result ){
            r = result[i];
            delete r._rev;
            delete r._key;
        }

        res.send( result );
    } catch( e ) {
        g_lib.handleException( e, res );
    }
})
.queryParam('type', joi.string().optional(), "Metric type (default all)")
.queryParam('since', joi.number().min(0).optional(), "Return since last specified minutes ago (default 60)")
.queryParam('uid', joi.string().optional(), "User ID (default none)")
.summary('Update message metrics.')
.description('Update message metrics.');