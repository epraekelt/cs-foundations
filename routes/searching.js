var express = require('express');
var router = express.Router();

router.get('/dfs', function(req, res, next) {
  res.render('searching/dfs');
});

router.get('/bfs', function(req, res, next) {
  res.render('searching/bfs');
});

module.exports = router;
