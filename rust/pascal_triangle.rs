//Gera o triangulo de pascal dentro de uma array
fn pascal() {
    const HEIGHT: usize = 5;
    const END: usize = HEIGHT + 1; 
    let mut triangle: [[i32; END]; HEIGHT] = [[0; END]; HEIGHT];
    
    triangle[0][1] = 1;
    let mut k = 1;
    while k < END {
        print!("{}", triangle[0][k]);
        k += 1;
    }
    print!("\n");

    let mut i = 1;
    while i < HEIGHT {
        let mut j = 1;
        while j < END {
            triangle[i][j] += triangle[i-1][j] + triangle[i-1][j-1];
            print!("{}", triangle[i][j]); 
            j += 1;
        }
        i += 1;
        print!("\n");
    }
}

fn main() {
    pascal();
}
