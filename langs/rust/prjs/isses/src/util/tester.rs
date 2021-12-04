use super::colors::norm;
use super::colors::fine;
use super::colors::suc;
use super::colors::fail;

pub fn zz_act(title: &str, act: &str, exp: &str, disp: &str){
    let title = format!("{} {:<15} <{:^15}>",norm("@"), title, fine(disp));
    let succes = format!("{:>20} acutal : {:<25} {} passed.", suc("Succes!"),act,suc("OK!"));
    let failed = format!("{:>10}** {}\n {:>20} --Expect : {}\n{:>22} bat was : {}", " ",fail("Fielid!"), " ", exp, " ", act);
    if act == exp { println!("{} {}",title, succes);} else { println!("{} {}",title, failed);}
}