// Learn more about F# at http://fsharp.org

open System


//[<Class>]
//type 'a BinaryTree =
//    member hd : 'a
//    member exists : 'a -> bool
//    member insert : 'a -> 'a BinaryTree
//end
type 'a stack =
    | EmptyStack
    | StackNode of 'a * 'a stack

module Stack =
    type 'a stack =
        | EmptyStack
        | StackNode of 'a * 'a stack
        
    let hd = function
        | EmptyStack -> failwith "Empty stack"
        | StackNode(hd, tl) -> hd
        
    let tl = function
        | EmptyStack -> failwith "Empty stack"
        | StackNode(hd, tl) -> tl
        
    let cons hd tl = StackNode(hd, tl)
    
    let empty = EmptyStack

type 'a tree =
    | EmptyTree
    | TreeNode of 'a * 'a tree * 'a tree

[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"
    0 // return an integer exit code
