
module.exports = function binarySearch(orderedArray, targetValue) {

  let headP = 0
  let tailP = orderedArray.length

  while (true) {
    let middleP = (headP + tailP) % 2 === 1 ? (headP + tailP - 1) / 2 : (headP + tailP) / 2

    switch (targetValue) {
      
      case orderedArray[headP]: return headP;
      
      case orderedArray[tailP]: return tailP;
      
      case orderedArray[middleP]: return middleP;
      
      default: {
        if (headP === middleP) {
          return -1
        }

        if (orderedArray[middleP] > targetValue) {
          tailP = middleP - 1
        } else {
          headP = middleP + 1
        }
      }
    }
  }
}