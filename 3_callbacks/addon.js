var addon = require('bindings')('addon');

addon(function(a,b){
  console.log(this)
  console.log(msg); // 'hello world'
});

// setInterval(() => {
//   addon(function(n){
//     console.log(this)
//     console.log(n); // 'hello world'
//   });
// }, 1000)
