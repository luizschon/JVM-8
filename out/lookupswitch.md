# **lookupswitch**

## **General Information**
Magic `0xCAFEBABE`  
Minor version `0`  
Major version `46`[`1.2`]  
Constant Pool Count `36`  
Access Flags `0x0021` [` ACC_SUPER ACC_PUBLIC `]  
This Class `7` `<lookupswitch>`  
Super Class `8` `<java/lang/Object>`  
Interfaces Count `0`  
Fields Count `0`  
Methods Count `3`  
Attributes Count `1`

## **Constant Pool**  

<details> <summary>Show more</summary> <hr>

### [1] *CONSTANT_Methodref_info*
- Class Index `8`
- Name And Type Index `19`

### [2] *CONSTANT_Fieldref_info*
- Class Index `20`
- Class Name `<java/lang/System>`
- Name And Type Index `21`
- Name And Type `<out:Ljava/io/PrintStream;>`

### [3] *CONSTANT_String_info*
- String Index `22`
- String `<Ops!>`

### [4] *CONSTANT_Methodref_info*
- Class Index `23`
- Name And Type Index `24`

### [5] *CONSTANT_Methodref_info*
- Class Index `7`
- Name And Type Index `25`

### [6] *CONSTANT_Methodref_info*
- Class Index `23`
- Name And Type Index `26`

### [7] *CONSTANT_Class_info*
- Name Index `27`
- Class Name `<lookupswitch>`

### [8] *CONSTANT_Class_info*
- Name Index `28`
- Class Name `<java/lang/Object>`

### [9] *CONSTANT_Utf8_info*
- Length `9`
- Bytes [ `chooseFar`]

### [10] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `(I)I`]

### [11] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `Code`]

### [12] *CONSTANT_Utf8_info*
- Length `15`
- Bytes [ `LineNumberTable`]

### [13] *CONSTANT_Utf8_info*
- Length `6`
- Bytes [ `<init>`]

### [14] *CONSTANT_Utf8_info*
- Length `3`
- Bytes [ `()V`]

### [15] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `main`]

### [16] *CONSTANT_Utf8_info*
- Length `22`
- Bytes [ `([Ljava/lang/String;)V`]

### [17] *CONSTANT_Utf8_info*
- Length `10`
- Bytes [ `SourceFile`]

### [18] *CONSTANT_Utf8_info*
- Length `17`
- Bytes [ `lookupswitch.java`]

### [19] *CONSTANT_NameAndType_info*
- Name Index `13`
- Descriptor Index `14`

### [20] *CONSTANT_Class_info*
- Name Index `29`
- Class Name `<java/lang/System>`

### [21] *CONSTANT_NameAndType_info*
- Name Index `30`
- Descriptor Index `31`

### [22] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `Ops!`]

### [23] *CONSTANT_Class_info*
- Name Index `32`
- Class Name `<java/io/PrintStream>`

### [24] *CONSTANT_NameAndType_info*
- Name Index `33`
- Descriptor Index `34`

### [25] *CONSTANT_NameAndType_info*
- Name Index `9`
- Descriptor Index `10`

### [26] *CONSTANT_NameAndType_info*
- Name Index `33`
- Descriptor Index `35`

### [27] *CONSTANT_Utf8_info*
- Length `12`
- Bytes [ `lookupswitch`]

### [28] *CONSTANT_Utf8_info*
- Length `16`
- Bytes [ `java/lang/Object`]

### [29] *CONSTANT_Utf8_info*
- Length `16`
- Bytes [ `java/lang/System`]

### [30] *CONSTANT_Utf8_info*
- Length `3`
- Bytes [ `out`]

### [31] *CONSTANT_Utf8_info*
- Length `21`
- Bytes [ `Ljava/io/PrintStream;`]

### [32] *CONSTANT_Utf8_info*
- Length `19`
- Bytes [ `java/io/PrintStream`]

### [33] *CONSTANT_Utf8_info*
- Length `7`
- Bytes [ `println`]

### [34] *CONSTANT_Utf8_info*
- Length `21`
- Bytes [ `(Ljava/lang/String;)V`]

### [35] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `(I)V`]

</details> <br>

## **Interfaces**

<details> <summary>Show more</summary> <hr>

</details><br>

## **Fields**

<details> <summary>Show more</summary> <hr>

</details><br>

## **Methods**
<details> <summary>Show more</summary> <hr>

### [0] `chooseFar` 
- Methods Access Flags `0x9` [` `]
- Name Index `9` `<chooseFar>`
- Descriptor Index `10` `<(I)I>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`11` `<Code>`
  - Attribute length `86`

- Specific info
  - Maximum stack size `1`
  - Maximum local variables `1`
  - Code length `46`
- Bytecode
```
0 iload_0
1 lookupswitch0: 9482 (9472)-1409045500: -1408171822 (-1408171832)-1094795586: -1094795576 (-1094795586)default: 51 (41)
```
### [0] LineNumberTable
- Generic info 
  - Attribute name index`12` `<LineNumberTable>`
  - Attribute length `22`

- Specific info
  - Line number table length `5`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|            6|  
|       1|        36|            7|  
|       2|        38|            8|  
|       3|        40|            9|  
|       4|        42|           10|  


</details><br>

### [1] `<init>` 
- Methods Access Flags `0x1` [` ACC_PUBLIC `]
- Name Index `13` `<<init>>`
- Descriptor Index `14` `<()V>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`11` `<Code>`
  - Attribute length `45`

- Specific info
  - Maximum stack size `2`
  - Maximum local variables `1`
  - Code length `13`
- Bytecode
```
0 aload_0
1 invokespecial #1 <java/lang/Object.<init> : ()V>  
4 getstatic #2 <java/lang/System.out : Ljava/io/PrintStream;>  
7 ldc #3 <Ops!>  
9 invokevirtual #4 <java/io/PrintStream.println : (Ljava/lang/String;)V>  
12 return
```
### [0] LineNumberTable
- Generic info 
  - Attribute name index`12` `<LineNumberTable>`
  - Attribute length `14`

- Specific info
  - Line number table length `3`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|           13|  
|       1|         4|           14|  
|       2|        12|           15|  


</details><br>

### [2] `main` 
- Methods Access Flags `0x9` [` `]
- Name Index `15` `<main>`
- Descriptor Index `16` `<([Ljava/lang/String;)V>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`11` `<Code>`
  - Attribute length `99`

- Specific info
  - Maximum stack size `2`
  - Maximum local variables `1`
  - Code length `55`
- Bytecode
```
0 getstatic #2 <java/lang/System.out : Ljava/io/PrintStream;>  
3 iconst_m1
4 invokestatic #5 <lookupswitch.chooseFar : (I)I>  
7 invokevirtual #6 <java/io/PrintStream.println : (I)V>  
10 getstatic #2 <java/lang/System.out : Ljava/io/PrintStream;>  
13 bipush 156
15 invokestatic #5 <lookupswitch.chooseFar : (I)I>  
18 invokevirtual #6 <java/io/PrintStream.println : (I)V>  
21 getstatic #2 <java/lang/System.out : Ljava/io/PrintStream;>  
24 iconst_0
25 invokestatic #5 <lookupswitch.chooseFar : (I)I>  
28 invokevirtual #6 <java/io/PrintStream.println : (I)V>  
31 getstatic #2 <java/lang/System.out : Ljava/io/PrintStream;>  
34 bipush 100
36 invokestatic #5 <lookupswitch.chooseFar : (I)I>  
39 invokevirtual #6 <java/io/PrintStream.println : (I)V>  
42 getstatic #2 <java/lang/System.out : Ljava/io/PrintStream;>  
45 sipush 10000
48 invokestatic #5 <lookupswitch.chooseFar : (I)I>  
51 invokevirtual #6 <java/io/PrintStream.println : (I)V>  
54 return
```
### [0] LineNumberTable
- Generic info 
  - Attribute name index`12` `<LineNumberTable>`
  - Attribute length `26`

- Specific info
  - Line number table length `6`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|           17|  
|       1|        10|           18|  
|       2|        21|           19|  
|       3|        31|           20|  
|       4|        42|           21|  
|       5|        54|           22|  


</details><br>

</details><br>

## **Attributes**
<details> <summary>Show more</summary> <hr>

### [0] SourceFile
- Generic info 
  - Attribute name index`17` `<SourceFile>`
  - Attribute length `2`

- Specific info
  - Source file name index `18` `<lookupswitch.java>`

</details><br>

