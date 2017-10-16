var express = require('express');
var router = express.Router();

router.get('/insertion', function(req, res, next) {
  res.render('sorting/insertion');
});

router.get('/selection', function(req, res, next) {
  res.render('sorting/selection');
});

router.get('/merge', function(req, res, next) {
  res.render('sorting/merge');
});

router.get('/heapsort', function(req, res, next) {
  res.render('sorting/heapsort');
});

router.get('/quicksort', function(req, res, next) {
  res.render('sorting/quicksort');
});

router.get('/bubble', function(req, res, next) {
  res.render('sorting/bubble')
});


module.exports = router;
