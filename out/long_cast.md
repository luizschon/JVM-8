# **long_cast**

## **General Information**
Magic `0xCAFEBABE`  
Minor version `0`  
Major version `46`[`1.2`]  
Constant Pool Count `38`  
Access Flags `0x0021` [` ACC_SUPER ACC_PUBLIC `]  
This Class `9` `<long_cast>`  
Super Class `10` `<java/lang/Object>`  
Interfaces Count `0`  
Fields Count `0`  
Methods Count `2`  
Attributes Count `1`

## **Constant Pool**  

<details> <summary>Show more</summary> <hr>

### [1] *CONSTANT_Methodref_info*
- Class Index `10`
- Name And Type Index `19`

### [2] *CONSTANT_Long_info*
- High Bytes `0xffffffff`
- Low Bytes `0xefffffff`
- Long `-268435457`

### [3] *(large numeric continued)*

### [4] *CONSTANT_Fieldref_info*
- Class Index `20`
- Class Name `<java/lang/System>`
- Name And Type Index `21`
- Name And Type `<out:Ljava/io/PrintStream;>`

### [5] *CONSTANT_Methodref_info*
- Class Index `22`
- Name And Type Index `23`

### [6] *CONSTANT_Methodref_info*
- Class Index `22`
- Name And Type Index `24`

### [7] *CONSTANT_Methodref_info*
- Class Index `22`
- Name And Type Index `25`

### [8] *CONSTANT_Methodref_info*
- Class Index `22`
- Name And Type Index `26`

### [9] *CONSTANT_Class_info*
- Name Index `27`
- Class Name `<long_cast>`

### [10] *CONSTANT_Class_info*
- Name Index `28`
- Class Name `<java/lang/Object>`

### [11] *CONSTANT_Utf8_info*
- Length `6`
- Bytes [ `<init>`]

### [12] *CONSTANT_Utf8_info*
- Length `3`
- Bytes [ `()V`]

### [13] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `Code`]

### [14] *CONSTANT_Utf8_info*
- Length `15`
- Bytes [ `LineNumberTable`]

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
- Length `14`
- Bytes [ `long_cast.java`]

### [19] *CONSTANT_NameAndType_info*
- Name Index `11`
- Descriptor Index `12`

### [20] *CONSTANT_Class_info*
- Name Index `29`
- Class Name `<java/lang/System>`

### [21] *CONSTANT_NameAndType_info*
- Name Index `30`
- Descriptor Index `31`

### [22] *CONSTANT_Class_info*
- Name Index `32`
- Class Name `<java/io/PrintStream>`

### [23] *CONSTANT_NameAndType_info*
- Name Index `33`
- Descriptor Index `34`

### [24] *CONSTANT_NameAndType_info*
- Name Index `33`
- Descriptor Index `35`

### [25] *CONSTANT_NameAndType_info*
- Name Index `33`
- Descriptor Index `36`

### [26] *CONSTANT_NameAndType_info*
- Name Index `33`
- Descriptor Index `37`

### [27] *CONSTANT_Utf8_info*
- Length `9`
- Bytes [ `long_cast`]

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
- Length `4`
- Bytes [ `(J)V`]

### [35] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `(D)V`]

### [36] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `(F)V`]

### [37] *CONSTANT_Utf8_info*
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

### [0] `<init>` 
- Methods Access Flags `0x1` [` ACC_PUBLIC `]
- Name Index `11` `<<init>>`
- Descriptor Index `12` `<()V>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`13` `<Code>`
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
  - Attribute name index`14` `<LineNumberTable>`
  - Attribute length `6`

- Specific info
  - Line number table length `1`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|            4|  


</details><br>

### [1] `main` 
- Methods Access Flags `0x9` [` `]
- Name Index `15` `<main>`
- Descriptor Index `16` `<([Ljava/lang/String;)V>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`13` `<Code>`
  - Attribute length `178`

- Specific info
  - Maximum stack size `3`
  - Maximum local variables `7`
  - Code length `90`
- Bytecode
```
0 ldc2_w #2 <-268435457>  
3 lstore_1
4 lload_1
5 l2d
6 dstore_3
7 lload_1
8 l2f
9 fstore #5
11 lload_1
12 l2i
13 istore #6
15 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
18 lload_1
19 invokevirtual #5 <java/io/PrintStream.println : (J)V>  
22 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
25 dload_3
26 invokevirtual #6 <java/io/PrintStream.println : (D)V>  
29 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
32 fload #5
34 invokevirtual #7 <java/io/PrintStream.println : (F)V>  
37 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
40 iload #6
42 invokevirtual #8 <java/io/PrintStream.println : (I)V>  
45 lload_1
46 lneg
47 lstore_1
48 lload_1
49 l2d
50 dstore_3
51 lload_1
52 l2f
53 fstore #5
55 lload_1
56 l2i
57 istore #6
59 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
62 lload_1
63 invokevirtual #5 <java/io/PrintStream.println : (J)V>  
66 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
69 dload_3
70 invokevirtual #6 <java/io/PrintStream.println : (D)V>  
73 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
76 fload #5
78 invokevirtual #7 <java/io/PrintStream.println : (F)V>  
81 getstatic #4 <java/lang/System.out : Ljava/io/PrintStream;>  
84 iload #6
86 invokevirtual #8 <java/io/PrintStream.println : (I)V>  
89 return
```
### [0] LineNumberTable
- Generic info 
  - Attribute name index`14` `<LineNumberTable>`
  - Attribute length `70`

- Specific info
  - Line number table length `17`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|            6|  
|       1|         4|            8|  
|       2|         7|           10|  
|       3|        11|           12|  
|       4|        15|           14|  
|       5|        22|           15|  
|       6|        29|           16|  
|       7|        37|           17|  
|       8|        45|           19|  
|       9|        48|           20|  
|      10|        51|           22|  
|      11|        55|           24|  
|      12|        59|           26|  
|      13|        66|           27|  
|      14|        73|           28|  
|      15|        81|           29|  
|      16|        89|           30|  


</details><br>

</details><br>

## **Attributes**
<details> <summary>Show more</summary> <hr>

### [0] SourceFile
- Generic info 
  - Attribute name index`17` `<SourceFile>`
  - Attribute length `2`

- Specific info
  - Source file name index `18` `<long_cast.java>`

</details><br>

