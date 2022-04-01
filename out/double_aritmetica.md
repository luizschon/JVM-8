# **double_aritmetica**

## **General Information**
Magic `0xCAFEBABE`  
Minor version `0`  
Major version `46`[`1.2`]  
Constant Pool Count `31`  
Access Flags `0x0021` [` ACC_SUPER ACC_PUBLIC `]  
This Class `8` `<double_aritmetica>`  
Super Class `9` `<java/lang/Object>`  
Interfaces Count `0`  
Fields Count `0`  
Methods Count `2`  
Attributes Count `1`

## **Constant Pool**  

<details> <summary>Show more</summary> <hr>

### [1] *CONSTANT_Methodref_info*
- Class Index `9`
- Name And Type Index `18`

### [2] *CONSTANT_Double_info*
- High Bytes `0x40588f5c`
- Low Bytes `0x28f5c28f`
- Double `98.24`

### [3] *(large numeric continued)*

### [4] *CONSTANT_Double_info*
- High Bytes `0x4060dbd7`
- Low Bytes `0xa3d70a4`
- Double `134.87`

### [5] *(large numeric continued)*

### [6] *CONSTANT_Fieldref_info*
- Class Index `19`
- Class Name `<java/lang/System>`
- Name And Type Index `20`
- Name And Type `<out:Ljava/io/PrintStream;>`

### [7] *CONSTANT_Methodref_info*
- Class Index `21`
- Name And Type Index `22`

### [8] *CONSTANT_Class_info*
- Name Index `23`
- Class Name `<double_aritmetica>`

### [9] *CONSTANT_Class_info*
- Name Index `24`
- Class Name `<java/lang/Object>`

### [10] *CONSTANT_Utf8_info*
- Length `6`
- Bytes [ `<init>`]

### [11] *CONSTANT_Utf8_info*
- Length `3`
- Bytes [ `()V`]

### [12] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `Code`]

### [13] *CONSTANT_Utf8_info*
- Length `15`
- Bytes [ `LineNumberTable`]

### [14] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `main`]

### [15] *CONSTANT_Utf8_info*
- Length `22`
- Bytes [ `([Ljava/lang/String;)V`]

### [16] *CONSTANT_Utf8_info*
- Length `10`
- Bytes [ `SourceFile`]

### [17] *CONSTANT_Utf8_info*
- Length `22`
- Bytes [ `double_aritmetica.java`]

### [18] *CONSTANT_NameAndType_info*
- Name Index `10`
- Descriptor Index `11`

### [19] *CONSTANT_Class_info*
- Name Index `25`
- Class Name `<java/lang/System>`

### [20] *CONSTANT_NameAndType_info*
- Name Index `26`
- Descriptor Index `27`

### [21] *CONSTANT_Class_info*
- Name Index `28`
- Class Name `<java/io/PrintStream>`

### [22] *CONSTANT_NameAndType_info*
- Name Index `29`
- Descriptor Index `30`

### [23] *CONSTANT_Utf8_info*
- Length `17`
- Bytes [ `double_aritmetica`]

### [24] *CONSTANT_Utf8_info*
- Length `16`
- Bytes [ `java/lang/Object`]

### [25] *CONSTANT_Utf8_info*
- Length `16`
- Bytes [ `java/lang/System`]

### [26] *CONSTANT_Utf8_info*
- Length `3`
- Bytes [ `out`]

### [27] *CONSTANT_Utf8_info*
- Length `21`
- Bytes [ `Ljava/io/PrintStream;`]

### [28] *CONSTANT_Utf8_info*
- Length `19`
- Bytes [ `java/io/PrintStream`]

### [29] *CONSTANT_Utf8_info*
- Length `7`
- Bytes [ `println`]

### [30] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `(D)V`]

</details> <br>

## **Interfaces**

<details> <summary>Show more</summary> <hr>

</details><br>

## **Fields**

<details> <summary>Show more</summary> <hr>

</details><br>

## **Methods**
<details> <summary>Show more</summary> <hr>

### [0] `<init>` 
- Methods Access Flags `0x1` [` ACC_PUBLIC `]
- Name Index `10` `<<init>>`
- Descriptor Index `11` `<()V>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`12` `<Code>`
  - Attribute length `29`

- Specific info
  - Maximum stack size `1`
  - Maximum local variables `1`
  - Code length `5`
- Bytecode
```
0 aload_0
1 invokespecial #1 <java/lang/Object.<init> : ()V>  
4 return
```
### [0] LineNumberTable
- Generic info 
  - Attribute name index`13` `<LineNumberTable>`
  - Attribute length `6`

- Specific info
  - Line number table length `1`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|            6|  


</details><br>

### [1] `main` 
- Methods Access Flags `0x9` [` `]
- Name Index `14` `<main>`
- Descriptor Index `15` `<([Ljava/lang/String;)V>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`12` `<Code>`
  - Attribute length `118`

- Specific info
  - Maximum stack size `5`
  - Maximum local variables `5`
  - Code length `62`
- Bytecode
```
0 ldc2_w #2 <98.240000>  
3 dstore_1
4 ldc2_w #4 <134.870000>  
7 dstore_3
8 getstatic #6 <java/lang/System.out : Ljava/io/PrintStream;>  
11 dload_1
12 dload_3
13 dadd
14 invokevirtual #7 <java/io/PrintStream.println : (D)V>  
17 getstatic #6 <java/lang/System.out : Ljava/io/PrintStream;>  
20 dload_1
21 dload_3
22 dsub
23 invokevirtual #7 <java/io/PrintStream.println : (D)V>  
26 getstatic #6 <java/lang/System.out : Ljava/io/PrintStream;>  
29 dload_1
30 dload_3
31 dmul
32 invokevirtual #7 <java/io/PrintStream.println : (D)V>  
35 getstatic #6 <java/lang/System.out : Ljava/io/PrintStream;>  
38 dload_1
39 dload_3
40 ddiv
41 invokevirtual #7 <java/io/PrintStream.println : (D)V>  
44 getstatic #6 <java/lang/System.out : Ljava/io/PrintStream;>  
47 dload_1
48 dneg
49 invokevirtual #7 <java/io/PrintStream.println : (D)V>  
52 getstatic #6 <java/lang/System.out : Ljava/io/PrintStream;>  
55 dload_3
56 dload_1
57 drem
58 invokevirtual #7 <java/io/PrintStream.println : (D)V>  
61 return
```
### [0] LineNumberTable
- Generic info 
  - Attribute name index`13` `<LineNumberTable>`
  - Attribute length `38`

- Specific info
  - Line number table length `9`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|            8|  
|       1|         4|            9|  
|       2|         8|           10|  
|       3|        17|           11|  
|       4|        26|           12|  
|       5|        35|           13|  
|       6|        44|           14|  
|       7|        52|           15|  
|       8|        61|           16|  


</details><br>

</details><br>

## **Attributes**
<details> <summary>Show more</summary> <hr>

### [0] SourceFile
- Generic info 
  - Attribute name index`16` `<SourceFile>`
  - Attribute length `2`

- Specific info
  - Source file name index `17` `<double_aritmetica.java>`

</details><br>

