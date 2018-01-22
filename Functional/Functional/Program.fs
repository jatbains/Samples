// Learn more about F# at http://fsharp.org

open System
open System.Data.Common

type Leaf = {value:int; left:Leaf option; right:Leaf option}

type animal =
| cat = 0
| dog = 1
| horse = 2
| cow = 3


let Pets =
    let myPet = animal.horse

    match myPet with 
    | animal.cat -> printfn "Meow"
    | animal.dog -> printfn "Woof"
    | animal.horse -> printfn "Neeeh"
    | animal.cow -> printfn "Moo"
    | _ -> printf "Hello"
    

let divide x y =
    match y with
    | 0 -> None
    | _ -> Some(x/y)
    

let rec fact x =
    if x < 1 then 1
    else x * fact(x-1)
 
let rec fib x =
    if x = 0 then 0
    elif x = 1 then 1
    else fib(x-1) + fib(x-2)

let lists() =
    let myList = [1,2,3,4]
    myList.GetHashCode()

let string_stuff =
    let greet = "Hello"
    greet + " World"

let while_loop =
    let mutable x = 1
    while (x < 10) do
        printfn "Number is %i" x
        x <- x + 1
    0
 
let is_Prime n =
    let rec checkPrime i =
        i > n/2 || (n%i <> 0 && checkPrime(i+1))
    checkPrime 2


type BNode =
    | Node of int * BNode
    //val mutable data : int 
    //val mutable next : Node
   


//let allocNode x =
//    let mutable node  = BNode
//    node.data <- x
//    node.next <- null
//    return node

  


[<EntryPoint>]

let main argv =
    let x = 20

    //printfn "Type is %A" (x.GetType())

    printfn "Fact of 10 is %i" (fact 10)
    printfn "Fib of 10 is %i" (fib 10)

    printfn "Hello World from F#!"

    printfn " %s " (string_stuff)

    if (divide 10 0).IsNone then
        printfn "Can't divide by zero"
    elif (divide 10 0).IsSome then
        printfn "Value is %A" ((divide 10 0).Value)

    while_loop |> ignore

    Pets |> ignore

    let c = Console.ReadKey() 
    0 
    // return an integer exit code
