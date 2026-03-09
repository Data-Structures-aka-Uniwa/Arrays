<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
</p>

<hr/>

<p align="center">
  <strong>Data Structures</strong>
</p>

<h1 align="center" style="letter-spacing: 1px;">
  Arrays
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Georgios Bardis, Assistant Professor
</p>
<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-bardis/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Co-supervisor: Georgios Meletiou, Laboratory Teaching Staff<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-meletiou/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Co-supervisor: Georgios Tselikis, Postdoctoral Researcher
</p>
<p align="center">
  <a href="https://eee.uniwa.gr/el/25-viografiko/1139-giorgos-tselikis" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/george-tselikis-5a7ba84/" target="_blank">LinkedIn</a>
</p>

</hr>

---

<p align="center">
  Athens, November 2022
</p>

---

<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20250527113657849446/Arrays-in-C.webp" width="250"/>
</p>

---

# INSTALL

## Arrays

This guide explains how to set up, build, and run the project on your local machine.

---

## 1. Installation & Compilation

### 1.1 Requirements

- A **C compiler** such as `gcc`

### 1.2 Clone the Repository

Open your terminal or command prompt and run:

```bash
git clone https://github.com/Data-Structures-aka-Uniwa/Arrays.git
cd Arrays/src
```

### 1.3 Steps
1. Save the program as:
```bash
main.c
```
2. Open a terminal and navigate to the project directory.
3. Create the output directory required by the program:
```bash
mkdir arr
```
4. Compile the program:
```bash
gcc main.c -o array_tool
```

---

## 2. Usage
Run the compiled executable:
```bash
./array_tool
```

---

## 3. Menu Options
| Option | Action          | Description                                              |
|------|-----------------|----------------------------------------------------------|
| 1    | Serial Search   | Finds a number by checking every element                |
| 2    | Quicksort       | Sorts a copy of the array and prints it                 |
| 3    | Binary Search   | Sorts the array and performs search in O(log n) time    |
| 4    | Merge           | Merges the current array with a new random sorted array |
| 5    | Print Array     | Displays the current array contents                     |
| 6    | Store to File   | Saves the array to `arr/array_N<size>.txt`              |
| -1   | Exit            | Frees memory and terminates the program                 |

---

## 4. Algorithm Details
### 4.1 Quicksort Partitioning
The algorithm uses a pivot-based partitioning strategy that separates smaller and larger elements around the pivot before recursively sorting each partition.

### 4.2 Binary Search Logic
Binary search reduces the search space by half in each step, making it significantly faster than linear search for large datasets, provided the array is already sorted.

---

## 5. Important Notes
### 5.1 Memory Management
The program uses malloc for dynamic memory allocation
free is called before program termination to avoid memory leaks

### 5.2 File Path
Ensure the directory `arr/` exists before selecting Option 6
Otherwise, the program may fail to write the file

### 5.3 Random Number Generation
The random seed is initialized using:
```c
srand(time(NULL));
```
This ensures different random numbers on each execution.