fn factorial(n: u64) -> u64{
/*Calcula o fatorial de n*/
    if n <= 1{
        return 1;
    }
    return n * factorial(n - 1);
}

fn euler(n: u64) -> f64 {
/*Retorna o valor de e utilizando a função   ∞
 *                                          \‾  1 / n!
 *                                          /_    
 *                                         n = 0
 *                                          */
    let mut i: u64 = 0;
    let mut sum: f64 = 0.0;
    while i < n {
        sum += 1.0 / (factorial(i) as f64);
        i += 1;
    }
    sum
}

fn main(){   
    println!("{:?}", euler(10));
}
