# **soma_certo**

## **General Information**
Magic `0xCAFEBABE`  
Minor version `0`  
Major version `46`[`1.2`]  
Constant Pool Count `17`  
Access Flags `0x0020` [` ACC_SUPER `]  
This Class `2` `<soma_certo>`  
Super Class `3` `<java/lang/Object>`  
Interfaces Count `1`  
Fields Count `0`  
Methods Count `2`  
Attributes Count `1`

## **Constant Pool**  

<details> <summary>Show more</summary> <hr>

### [1] *CONSTANT_Methodref_info*
- Class Index `3`
- Name And Type Index `13`

### [2] *CONSTANT_Class_info*
- Name Index `14`
- Class Name `<soma_certo>`

### [3] *CONSTANT_Class_info*
- Name Index `15`
- Class Name `<java/lang/Object>`

### [4] *CONSTANT_Class_info*
- Name Index `16`
- Class Name `<Somar>`

### [5] *CONSTANT_Utf8_info*
- Length `6`
- Bytes [ `<init>`]

### [6] *CONSTANT_Utf8_info*
- Length `3`
- Bytes [ `()V`]

### [7] *CONSTANT_Utf8_info*
- Length `4`
- Bytes [ `Code`]

### [8] *CONSTANT_Utf8_info*
- Length `15`
- Bytes [ `LineNumberTable`]

### [9] *CONSTANT_Utf8_info*
- Length `5`
- Bytes [ `somar`]

### [10] *CONSTANT_Utf8_info*
- Length `5`
- Bytes [ `(II)I`]

### [11] *CONSTANT_Utf8_info*
- Length `10`
- Bytes [ `SourceFile`]

### [12] *CONSTANT_Utf8_info*
- Length `19`
- Bytes [ `interface_test.java`]

### [13] *CONSTANT_NameAndType_info*
- Name Index `5`
- Descriptor Index `6`

### [14] *CONSTANT_Utf8_info*
- Length `10`
- Bytes [ `soma_certo`]

### [15] *CONSTANT_Utf8_info*
- Length `16`
- Bytes [ `java/lang/Object`]

### [16] *CONSTANT_Utf8_info*
- Length `5`
- Bytes [ `Somar`]

</details> <br>

## **Interfaces**

<details> <summary>Show more</summary> <hr>

- Interface: `4` `<Somar>`
</details><br>

## **Fields**

<details> <summary>Show more</summary> <hr>

</details><br>

## **Methods**
<details> <summary>Show more</summary> <hr>

### [0] `<init>` 
- Methods Access Flags `0x0` [` `]
- Name Index `5` `<<init>>`
- Descriptor Index `6` `<()V>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`7` `<Code>`
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
  - Attribute name index`8` `<LineNumberTable>`
  - Attribute length `6`

- Specific info
  - Line number table length `1`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|           19|  


</details><br>

### [1] `somar` 
- Methods Access Flags `0x1` [` ACC_PUBLIC `]
- Name Index `9` `<somar>`
- Descriptor Index `10` `<(II)I>`
- Attribute Count `1`
<details><summary>Show attributes</summary>

### [0] Code
- Generic info 
  - Attribute name index`7` `<Code>`
  - Attribute length `28`

- Specific info
  - Maximum stack size `2`
  - Maximum local variables `3`
  - Code length `4`
- Bytecode
```
0 iload_1
1 iload_2
2 iadd
3 ireturn
```
### [0] LineNumberTable
- Generic info 
  - Attribute name index`8` `<LineNumberTable>`
  - Attribute length `6`

- Specific info
  - Line number table length `1`  

| Number | Start PC | Line Number |  
|--------|----------|-------------|  
|       0|         0|           21|  


</details><br>

</details><br>

## **Attributes**
<details> <summary>Show more</summary> <hr>

### [0] SourceFile
- Generic info 
  - Attribute name index`11` `<SourceFile>`
  - Attribute length `2`

- Specific info
  - Source file name index `12` `<interface_test.java>`

</details><br>

