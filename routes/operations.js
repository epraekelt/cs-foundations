var express = require('express');
var router = express.Router();

router.get('/karatsuba', function(req, res, next) {
  res.render('operations/karatsuba');
});

router.get('/school-addition', function(req, res, next) {
  res.render('operations/school-addition');
});

router.get('/school-multiplication', function(req, res, next) {
  res.render('operations/school-multiplication');
});

module.exports = router;
