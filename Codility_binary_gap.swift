import Foundation

public func solution(_ N : Int) -> Int {
    // write your code in Swift 4.2.1 (Linux)
    var binaryGap:Int = 0
    var maxGap:Int = 0
    let binaryStr = String(N, radix: 2, uppercase: false)
    for (_,char) in binaryStr.enumerated() {
      //  print("char = \(char)")
        if char == "0" {
                binaryGap += 1
        }
        else {
            if binaryGap > maxGap {
                maxGap = binaryGap
            }
            binaryGap = 0
        }
    }
    return maxGap
}
