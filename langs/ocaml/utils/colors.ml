
let black   = "\x1b[30m"
let red     = "\x1b[31m"
let green   = "\x1b[32m"
let yellow  = "\x1b[33m"
let blue    = "\x1b[34m"
let magenta = "\x1b[35m"
let cyan    = "\x1b[36m"
let white   = "\x1b[37m"
let reset   = "\x1b[0m"

let suc cs   = green ^ cs ^ reset
let norm cs  = blue ^ cs ^ reset
let err cs   = red ^ cs ^ reset
let fine cs  = yellow ^ cs ^ reset
