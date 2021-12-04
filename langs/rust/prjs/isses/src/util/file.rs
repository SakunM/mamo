use std::fs::File;
use std::io::prelude::*;

pub fn read_file(path: &str) -> Vec<String>{
  let mut f = File::open(path).expect("file not found");
  let mut contents = String::new();
  f.read_to_string(&mut contents).expect("err oc!");
  let mut res:Vec<String> = Vec::new();
  for line in contents.lines(){ res.push(line.trim().to_string());}
  res
}