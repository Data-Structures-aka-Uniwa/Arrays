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

# README

## Arrays

A command-line interface (**CLI**) application written in **C** that performs various algorithmic operations on an array of random integers.

---

## Table of Contents

| Section | Folder/File | Description |
|------:|-------------|-------------|
| 1 | `INSTALL.md` | Installation and compilation instructions |
| 2 | `README.md` | Project overview and usage guide |
| 3 | `assign/` | Assignment description images |
| 3.1 | `assign/Arrays.png` | Arrays assignment image (English) |
| 3.2 | `assign/Πίνακες.png` | Arrays assignment image (Greek) |
| 4 | `src/` | Source code and related input files |
| 4.1 | `src/arrays.c` | Main C source file implementing array operations |
| 4.2 | `src/arr/` | Sample array input files |
| 4.2.1 | `src/arr/array_N10.txt` | Example array input with 10 elements |
| 4.2.2 | `src/arr/array_N20.txt` | Example array input with 20 elements |

---

## 1. Features

### 1.1 Dynamic Array Generation
Creates an array of size **N** and populates it with random integers between **30 and 50**.

### 1.2 Search Algorithms

**Serial Search**
- Linear scan of the array
- Counts the number of iterations required to find the element

**Binary Search**
- Recursive implementation
- Automatically sorts the array before searching
- Time complexity: **O(log n)**

---

## 2. Sorting

### 2.1 Quicksort Algorithm

The program sorts the array using **Quicksort** with pivot-based partitioning (Hoare/Lomuto style).

---

## 3. Merging

- Generates a **second random array**
- Sorts both arrays
- Merges them into a **single sorted array of size 2N**

---

## 4. File Persistence

Exports the array contents into a **formatted text file** stored in a dedicated directory.