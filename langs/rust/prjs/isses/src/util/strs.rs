
pub fn to_nums(ss: String) -> Vec<i32>{ ss.split_whitespace().map(|it| it.parse().unwrap()).collect()}

pub fn neg1(ns: Vec<i32>) -> Vec<i32>{ let mut res:Vec<i32> = Vec::new(); for n in ns{ res.push(n-1);} res}
fn test_neg1(){ let ans = neg1(vec![2,3]); println!("ans is {:?}",ans);}   // exp is exp

pub fn from_strs(ss: Vec<&str>) -> Vec<String>{ ss.iter().map(|s| s.to_string()).collect() }
// fn test_fsr(){ let ans = from_strs(vec!["hoge","fuga"]); println!("ans is {:?}",ans);}   // exp is exp

pub fn from_strings(ss: &Vec<String>) -> Vec<&str> { ss.iter().map(|it| &it[..]).collect()}
// fn test_fss(){ let ans = from_strings(&vec!["hoge".to_string(), "fuga".to_string()]); println!("{:?}",ans);}

pub fn reverse(s: &str) -> String{ s.chars().rev().collect()}