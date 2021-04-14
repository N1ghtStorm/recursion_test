use std::time::{Instant};

fn main() {
    let start_1 = Instant::now();
    some_1(0);
    let duration_1 = start_1.elapsed();
    println!("{:?}", duration_1);

    let mut a = 0;
    let start_2 = Instant::now();
    some_2(&mut a);
    let duration_2 = start_2.elapsed();
    println!("{:?}", duration_2);
}


fn some_1(mut a: i32){
    if a >= 15000 {
        return;
    }
    a += 1;
    some_1(a);
}

fn some_2(a: &mut i32){
    if *a >= 15000 {
        return;
    }
    *a+=1;
    some_2(a);
}