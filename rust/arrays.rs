use std::f32;

fn print_vec<const N: usize>(vec: [i32; N]) {
    let mut i: usize = 0;
    while i < N {
        println!("{:?}", vec[i]);
        i += 1;
    }
}

fn print_even<const N: usize>(vec: [i32; N]) {
/*imprime somente os valores pares de um array*/
    let mut i: usize = 0;
    while i < N {
        if vec[i] % 2 == 0 {
            println!("{:?}", vec[i]);
        }
        i += 1;
    }
}

fn set_positive<const N: usize>(mut vec: [i32; N]) {
/*produz o módulo dos elementos negativos de um array*/
    let mut i: usize = 0;
    while i < N {
        if vec[i] < 0 {
            vec[i] *= -1;
        }
        i += 1;
    }
}

fn find_max<const N: usize>(vec: [i32; N]) -> i32{
/*encontra o maior numero de um array*/
    let mut max: i32 = i32::MIN;
    let mut i: usize = 0;
    while i < N {
        if vec[i] > max {
            max = vec[i];
        }    
        i += 1;
    }
    max
}

fn replace_all<const N: usize>(elem: i32, mut vec: [i32; N]) {
/*substitui todaas as ocorrencias e um dado elemento em um array por -1*/
    let mut i: usize = 0;
    while i < N {
        if vec[i] == elem {
            vec[i] = -1;
        }
        i += 1;
    }
}

fn read_vec<const N: usize>(mut vec: [i32; N]) {
/*Preenche um array com valores crescentes*/
    let mut i: usize = 0;
    while i < N {
        vec[i] = i as i32;
        i += 1;
    }
}

fn is_sorted<const N: usize>(vec: [i32; N]) -> bool {
/*Verifica se um array esta em ordem crescente*/
    let mut i: usize = 1;
    while i < N {
        if vec[i] < vec[i-1] {
            return false
        }
        i += 1;
    }
    return true
}

fn distances<const N: usize>(points: [i32; N]) {
/*Informa a distancia entre dois pontos consecutivos contidos em um array*/
    let mut i = 2;
    while i < N {
        let distance: i32 = (points[i] - points[i-2]).pow(2) + (points[i+1] - points[i-1]).pow(2);
        println!("distancia = {:?}", (distance as f32).sqrt());
        i += 2;
    }
}

fn reverse<const N: usize>(mut vec: [i32; N]) {
/*Inverte os elementos de um vetor*/
    let mut i: usize = 0; 
    while i < N/2 {
        let tmp = vec[i];
        vec[i] = vec[N-i-1];
        vec[N-i-1] = tmp;
        i += 1;
    }
    print_vec(vec);
}

fn vector_copy<const N: usize>(vec: [i32; N], mut void: [i32; N]) {
/*Copia o conteúdo de um array para outro*/
    let mut i: usize = 0;
    while i < N {
        void[i] = vec[i];
        i += 1; 
    }
    print_vec(void);
}

fn vector_insert<const N: usize>(mut vec: [i32; N], elem: i32) -> bool {
/*Insere um elemento em todas as posicoes iguais a '-1' em um array*/
    let mut i: usize = 0;
    let mut hppn: bool = false;
    while i < N {
        if vec[i] == -1 {
            vec[i] = elem;
            hppn = true;
        }
        i += 1;
    }
    println!("{:?}", hppn);
    hppn
}

fn vector_remove<const N: usize>(mut vec: [i32; N], pos: usize) {
/*Recebe um array e uma posição e remove o elemento do array nesta posição, da panic!() em caso de
 * acesso inválido*/
    if pos >= N {
        panic!("Impossível modificar essa posição!");
    } else {
        vec[pos] = -1;
        print_vec(vec);
    }
}

fn vector_defrag<const N: usize>(mut vec: [i32; N]) {
/*Recebe um array e move seus elementos de modo a defragmentar os elementos válidos na sequencia*/
    let mut i: usize = 0;
    while i < N {
       if vec[i] == -1 {
           let mut j = 1;
           while i+j < N {
               if vec[i + j] != -1 {
                    vec[i] = vec[i+j];
                    vec[i+j] = -1;
                    break;
               }
               j += 1;
           }
       } 
       i += 1;
    }
    print_vec(vec);
}

fn vector_concat<const N: usize, const M: usize, const O: usize>(vec1: [i32; N], vec2: [i32; M], mut vec3: [i32; O]) {
/*Recebe três vetores e concatena os dois primeiros no terceiro*/
    let mut k: usize = 0;
    for i in 0..N {
        vec3[k] = vec1[i];
        k += 1;
    }
    for j in 0..M {
        vec3[k] = vec2[j];
        k += 1;
    }
    print_vec(vec3);
}

fn merge<const N: usize, const M: usize, const K: usize>(vec1: [i32; N], vec2: [i32; M], mut void: [i32; K]) {
/*Recebe dois vetores em ordem crescente e mescla ordenadamente os conteudos destes em um terceiro
 * vetor.*/
    let mut j = 0;
    let mut i = 0;
    let mut k = 0;
    while (i < N) && (j < M) {
        if vec1[i] <= vec2[j] {
            void[k] = vec1[i];
            i += 1;
        } else {
            void[k] = vec2[j];
            j += 1;
        }
        k += 1;
    }
    while i < N {
        void[k] = vec1[i];
        k += 1;
        i += 1;
    }
    while j < M {
        void[k] = vec2[j];
        k += 1;
        j += 1;
    }
    print_vec(void);
}

fn max_sum_slice<const N: usize>(vec: [i32; N]) -> i32 {
/*Recebe um vetor de inteiros e retorna a soma do segmento de soma maxima*/
    let mut max = i32::MIN;
    let mut slc = 1;
    while slc < N {
        let mut i = 0;
        while N > (i+slc){
            let mut sum = 0;
            for j in i..(i+slc) {
                sum += vec[j];
            }
            if sum > max {
                max = sum;
            }
            i += 1;
        } 
        slc += 1; 
    }
    max
}

fn count_elements<const N: usize>(vec: [i32; N]) {
/*Conta as ocorrecias de um elemento de um array em um array de contagem*/
    let mut count: [i32; 255] = [0; 255];
    for i in 0..N {
        let k = vec[i];
        count[k as usize] += 1;
    }
    print_vec(count);
}

fn min_bills<const N: usize>(mut valor: i32, bills: [i32; N]) {
/*Recebe um valor inteiro e um vetor com as possíveis cédulas e imprime a quantidade mínima de cédulas equivalente ao valor*/
    let mut count: [i32; N] = [0; N];
    for i in 0..N {
        let mut hppn: bool = false;
        while valor >= bills[i] {
            hppn = true;
            valor -= bills[i];
            count[i] += 1;
        }
        if hppn {
            println!("x{} de R${},00", count[i], bills[i]);
        }
    }
    if valor > 0 {
        println!("Sobraram R${},00", valor);
    }
}

fn contem<const N: usize>(x: i32, v: [i32;N]) -> bool {
/*Função auxiliar: verifica se um dado numero esta contido em um array*/
    for i in 0..N {
        if x == v[i] {
            return true
        }
    }
    false
}

fn bubble_sort<const N: usize>(mut v: [i32; N]) {
/*Função auxiliar: Ordena um array com bubble sort*/
    let mut swap = true;
    while swap {
        swap = false;
        for j in 0..N-1 {
            if v[j] > v[j+1] {
                let tmp = v[j];
                v[j] =  v[j+1];
                v[j+1] = tmp;
                swap = true;
            }
        }
    }
}

fn vec_union<const N: usize, const M: usize, const K: usize>(v1: [i32; N], v2: [i32;M], mut v3: [i32; K]) {
/*Realiza a união de dois vetores em um terceiro*/
    let mut k: usize = 0;
    for i in 0..N {
        v3[k] = v1[i];
        k += 1;
    }
    for j in 0..M {
        if !contem(v2[j], v3) {
            v3[k] = v2[j];
            k += 1;
        }
    }
    let mut swap = true;
    while swap {
        swap = false;
        for j in 0..K-1 {
            if v3[j] > v3[j+1] {
                let tmp = v3[j];
                v3[j] =  v3[j+1];
                v3[j+1] = tmp;
                swap = true;
            }
        }
    }
    print_vec(v3);
}

fn vec_inter<const N: usize, const M: usize, const K: usize>(v1: [i32; N], v2: [i32; M], mut v3: [i32; K]) {
/*Realiza a intersecção de dois vetores em um terceiro*/
    for i in 0..N {
        if contem(v1[i], v2) {
            v3[i] = v1[i];
        }
    }
    print_vec(v3);
}

fn main() {
    const N: usize = 10;
    let mut numeros: [i32; 7] = [0,1,2,3,4,5,6];
    let mut inteiros: [i32; N] = [-5,-4,-3,-2,-1,0,1,2,3,4];
    let mut void: [i32; 7] = [0; 7];
    let mut replace: [i32; N] = [0,-1,2,-1,3,4,5,-1,7,9];
    let points: [i32; 6] = [0,1,1,0,0,0];
    let mut void2: [i32; 20] = [0; 20];
    let mx: [i32; 12] = [5, 2,-2,-7, 3,14,10,-3, 9,-6, 4, 1];
    let bill: [i32; 5] = [100,50,20,10,5];
    //print_even(numeros);
    //set_positive(inteiros);
    //println!("{}",find_max(numeros));
    //replace_all(4, numeros);
    //read_vec(void);
    //println!("{}",is_sorted(numeros));
    //distances(points);
    //reverse(numeros);
    //vector_copy(inteiros, void);
    //vector_insert(replace, 8);
    //vector_remove(numeros, 25);
    //vector_defrag(replace);
    //vector_concat(numeros, inteiros, void2);
    //merge(numeros, inteiros, void);
    /*let max = max_sum_slice(mx);
    println!("{}", max);*/
    //count_elements(numeros);
    //min_bills(209, bill);
    //vec_union(numeros, inteiros, void);
    vec_inter(numeros, inteiros, void);
}
