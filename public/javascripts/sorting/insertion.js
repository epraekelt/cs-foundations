var i = 1;                     //  set your counter to 1

function slowExecution(chart, length, array, speed) {
  setTimeout(() => {
    var temp = array[i];
    for(var j = i - 1; j >= 0 && array[j] > temp; j--) {
      array[j+1] = array[j];
    }
    array[j+1] = temp;

    chart.data.labels = [...array];
    chart.data.datasets[0].data = [...array];
    chart.update();

    if (++i < length) slowExecution(chart, length, array, speed);
  }, speed)
}


let insertion = (chart, array, speed) => {
  var length = array.length;

  slowExecution(chart, length, array, speed);

  // for(var i = 1; i < length; i++) {
  //   var temp = array[i];
  //   for(var j = i - 1; j >= 0 && array[j] > temp; j--) {
  //     array[j+1] = array[j];
  //   }
  //   array[j+1] = temp;
  // }

  return array;
}

function runAlgo() {
  wrapAlgo(insertion);
}
