#![allow(unused)]
use std::io;
use std::collections::HashMap;
use std::collections::VecDeque;
// use itertools::Itertools;

mod util;
use util::file;
use util::tester::zz_act;
use util::colors::*;
use util::strs::to_nums;
use util::strs::neg1;
use util::strs::from_strs;
use util::strs::from_strings;
use util::strs::reverse;
use util::utils::maxs;
use util::utils::mins;
use util::utils::sums;

fn to_usize(arg:Vec<i32>) -> Vec<usize>{ arg.iter().map(|ar| *ar as usize).collect()}

fn m001(ss: Vec<&str>) -> Vec<i32>{ to_nums(ss[0].to_string())}   
fn test_m(){
    let arg = vec!["10 3 2 5 7 8"]; let res = m001(arg); println!("res: {:?}",res);
}

fn max2(a:i32, b:i32) -> i32{ if a > b {return a;} else{ return b;}}
fn domain(ns: Vec<i32>) -> i32{
    let mut ans = 0;
    let mut dp:Vec<i32> = Vec::new();
    for i in 0..ns.len()-1 {
        dp.push(ns[i]);
        if i > 0 { dp[i] = max2(dp[i-1], dp[i]);}
        if i > 1 { dp[i] = max2(dp[i], dp[i-2] + ns[i]);}
        ans = max2(ans, dp[i]);
    }
    for i in 0..ns.len()-1 {
        dp[i] = ns[i+1];
        if i > 0 { dp[i] = max2(dp[i-1], dp[i]);}
        if i > 1 { dp[i] = max2(dp[i], dp[i-2] + ns[i+1]);}
        ans = max2(ans, dp[i]);
    }
    ans
}
fn test_d(){
    let res = domain(vec![10,3,2,5,7,8]);
    println!("{}",res);
}

fn domains(ss: Vec<String>)-> Vec<String>{  // main
    let ns = m001(from_strings(&ss));
    let res = domain(ns);
    vec![res.to_string()]
}
fn test(){
    let arg = vec!["10 3 2 5 7 8"];
    let ans = domains(from_strs(arg)); println!("{:?}",ans);
}

fn user() -> Vec<String>{
    let mut user = String::new(); let mut res:Vec<String> = Vec::new();
    io::stdin().read_line(&mut user).unwrap(); res.push(user.trim().to_string());
    // let mut user = String::new(); io::stdin().read_line(&mut user).unwrap(); res.push(user.trim().to_string());
    let lim = res[0].len() - 1;
    for _ in 0..lim { let mut user = String::new(); io::stdin().read_line(&mut user).unwrap(); res.push(user.trim().to_string());}
    res
}

fn product(){
    let res:Vec<String> = user();
    // println!("{:?}",res);
    let ans = domains(res); for an in ans{ println!("{}",an);}
}

fn developer(arg: &str, res: &str, name: &str) {
    let ans = domains(file::read_file(arg)); let exp = file::read_file((res));
    zz_act("M001 Test",&format!("{:?}",ans),&format!("{:?}",exp),name);
}
fn develop(){
    let issue1 = "a:/pj/mamo/refs/isses/issue1.txt"; let result1 = "a:/pj/mamo/refs/isses/result1.txt";
    let issue2 = "a:/pj/mamo/refs/isses/issue2.txt"; let result2 = "a:/pj/mamo/refs/isses/result2.txt";
    let issue3 = "a:/pj/mamo/refs/isses/issue3.txt"; let result3 = "a:/pj/mamo/refs/isses/result3.txt";
    let issue4 = "a:/pj/mamo/refs/isses/issue4.txt"; let result4 = "a:/pj/mamo/refs/isses/result4.txt";
    let issue5 = "a:/pj/mamo/refs/isses/issue5.txt"; let result5 = "a:/pj/mamo/refs/isses/result5.txt";
    let issue6 = "a:/pj/mamo/refs/isses/issue6.txt"; let result6 = "a:/pj/mamo/refs/isses/result6.txt";
    developer(issue1,result1,"test_1"); developer(issue2,result2,"test_2");
    developer(issue3,result3,"test_3"); developer(issue4,result4,"test_4"); 
    developer(issue5,result5,"test_5"); developer(issue6,result6,"test_6");
}

fn refactor(){
    let issue = "a:/pj/mamo/refs/isses/issue1.txt"; let result = "a:/pj/mamo/refs/isses/result1.txt";
    let arg = file::read_file(issue); let exp = file::read_file(result);
    // println!("{:?}",arg); println!("{:?}",exp);
    let ans = domains(arg);
    zz_act("M001 Test", & format!("{:?}",ans), & format!("{:?}",exp), "refactor()");
}
// M001 m001 domain user
fn main() {
    // test();
    // refactor();
    develop();
    // product();
}