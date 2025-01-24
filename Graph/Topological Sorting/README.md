# Topological Sorting for Directed Acyclic Graph (DAG)

## Introduction
**Topological Sorting** is a linear ordering of vertices such that for every directed edge \( u -> v \), vertex \( u \) appears before \( v \) in the ordering.

### Key Notes:
- Topological sorting is only possible for **Directed Acyclic Graphs (DAGs)**.
- If a graph contains a cycle, topological sorting is **not possible**.

---

## Visual Representation of Topological Sorting

### Example 1:
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20230914164620/Topological-sorting.png" alt="Topological Sorting Example 1" width="600">

---

### Steps for Topological Sorting:

#### Step 1:
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20230914175432/file.png" alt="Step 1" width="600">

#### Step 2:
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20230914175548/file.png" alt="Step 2" width="600">

#### Step 3:
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20230914175605/file.png" alt="Step 3" width="600">

#### Step 4:
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20230914175620/file.png" alt="Step 4" width="600">

#### Step 5:
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20230914175633/file.png" alt="Step 5" width="600">

---

## Applications of Topological Sorting:
1. **Task Scheduling**:
   - Ordering tasks while respecting dependencies (e.g., build systems).
2. **Course Prerequisite Resolution**:
   - Determining the order in which courses should be taken.
3. **Dependency Resolution**:
   - Resolving dependencies in software systems or libraries.

---