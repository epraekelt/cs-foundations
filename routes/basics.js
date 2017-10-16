var express = require('express');
var router = express.Router();

router.get('/complexity', function(req, res, next) {
  res.render('basics/complexity');
});

router.get('/heap-stack', function(req, res, next) {
  res.render('basics/heap-stack');
});

module.exports = router;
