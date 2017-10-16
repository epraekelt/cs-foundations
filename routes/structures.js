var express = require('express');
var router = express.Router();

router.get('/linked-list', function(req, res, next) {
  res.render('structures/linked-list');
});

router.get('/doubly-linked-list', function(req, res, next) {
  res.render('structures/doubly-linked-list');
});

router.get('/skip-list', function(req, res, next) {
  res.render('structures/skip-list');
});

router.get('/avl-tree', function(req, res, next) {
  res.render('structures/avl-tree');
});

router.get('/binary-tree', function(req, res, next) {
  res.render('structures/binary-tree');
});

router.get('/adjacency-list', function(req, res, next) {
  res.render('structures/adjacency-list')
});


module.exports = router;
