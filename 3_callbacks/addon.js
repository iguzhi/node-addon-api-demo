var addon = require('bindings')('addon');

addon(function(msg){
  console.log(this)
  console.log(msg); // 'hello world'
});
