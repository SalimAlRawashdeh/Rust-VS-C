#![allow(dead_code, unused_variables, unused_imports, unused_mut)]
use std::fs::File;
use std::io::{BufReader, Read};
use std::time::Instant;
use std::io::SeekFrom;
use std::io::Seek;
use std::io::BufRead;

#[allow(dead_code)]
#[derive(Copy, Clone)]
struct ForIntegersOnly {
    a: i32,
    b: i32,
    c: i32,
}

#[allow(dead_code)]
struct ForIntegersAndStrings {
    uno: i32,
    dos: i32,
    tres: String,
}

//Bubble sort for integers
fn bubble_sort_int<T: Ord + Copy>(arr: &mut [T]) {
    let len = arr.len();
    for i in 0..len {
        for j in 0..len - 1 - i {
            if arr[j] > arr[j + 1] {
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}




fn bubble_sort_strings<T: Ord>(arr: &mut [T]) {
    let len = arr.len();
    for i in 0..len {
        for j in 0..len - i - 1 {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}

fn bubble_sort_struct_int(array: &mut [ForIntegersOnly]) {
    let len = array.len();
    for i in 0..len {
        for j in 0..len - 1 - i {
            if array[j].a > array[j + 1].a {
                let temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

fn bubble_sort_struct_str(array: &mut [ForIntegersAndStrings]) {
    let len = array.len();
    for i in 0..len {
        for j in 0..len - 1 - i {
            if array[j].tres > array[j + 1].tres {
                array.swap(j, j + 1);
            }
        }
    }
}

fn main() {
// Code to open integers file and translate it into an array
    let mut str = String::new();
    let file = File::open("integers.txt").expect("Error in reading file");
    let mut bufferreader = BufReader::new(file);
    bufferreader.read_to_string(&mut str).expect("Unable to read line");
    let mut array_int: Vec<i64> = str.lines().map(|x| x.parse::<i64>().unwrap()).collect();

    let mut countint = 0;

    for _element in array_int.iter() {
        countint = countint + 1;
    }

// Code to sort the araray of integers 
    let time_int = Instant::now();
    bubble_sort_int(&mut array_int);
    let time_elapsed_int = time_int.elapsed();
    print!("Rust,");
    print!(" Integers,");
    print!(" {:?},", countint);
    println!(" {:?}", time_elapsed_int);

    bufferreader.seek(SeekFrom::Start(0)).expect("Failed to reset cursor");
    let mut array: Vec<ForIntegersOnly> = Vec::new();
    let mut array2: Vec<ForIntegersAndStrings> = Vec::new();
    for line in bufferreader.lines() {
        if let Ok(a) = line {
            let a = a.trim().parse::<i32>().expect("Failed to parse integer");
            let b = a + 1;
            let c = a + 2;
            let my_struct = ForIntegersOnly { a, b, c };
            array.push(my_struct);

            let uno = a;
            let dos = a + 1;
            let tres = a.to_string();
            let my_struct2 = ForIntegersAndStrings { uno, dos, tres };
            array2.push(my_struct2);
        }
    }

    

// Open and read string file
    let mut str = String::new();
    let file = File::open("strings.txt").expect("Error in reading file");
    let mut bufferreader = BufReader::new(file);


    bufferreader.read_to_string(&mut str).expect("Unable to read line");
    let mut array_string: Vec<String> = str.lines().map(|s| s.to_string()).collect();

    let mut countstr = 0;
    for _element in array_string.iter() {
        countstr = countstr + 1;
    }

// Time and output the strings 
if countstr <= 50000 {   
    let time_str = Instant::now();
    bubble_sort_strings (&mut array_string);
    let time_elapsed_str = time_str.elapsed();

    print!("Rust,");
    print!(" Strings,");
    print!(" {:?},", countstr);
    println!(" {:?}", time_elapsed_str);

}

if countint <= 75000 {
    let time_struct_int = Instant::now();
    bubble_sort_struct_int(&mut array);
    let time_elapsed_struct_int = time_struct_int.elapsed();

    print!("Rust,");
    print!(" StructINT,");
    print!(" {:?},", countint);
    println!(" {:?}", time_elapsed_struct_int);

    let time_struct_str = Instant::now();
    bubble_sort_struct_str(&mut array2);
    let time_elapsed_struct_str = time_struct_str.elapsed();

    print!("Rust,");
    print!(" StructSTR,");
    print!(" {:?},", countint);
    println!(" {:?}", time_elapsed_struct_str);
}
}