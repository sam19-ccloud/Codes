// Store student data temporarily in browser memory (for now)
let students = [];
let studentCount = 0;

document.getElementById("marksForm").addEventListener("submit", function(event) {
  event.preventDefault();

  const name = document.getElementById("studentName").value.trim();
  const marks = parseInt(document.getElementById("studentMarks").value);

  if (name === "" || isNaN(marks) || marks < 0 || marks > 100) {
    alert("Please enter valid details!");
    return;
  }

  // Calculate grade
  let grade;
  if (marks >= 90) grade = "A";
  else if (marks >= 85) grade = "B";
  else if (marks >= 75) grade = "C";
  else if (marks >= 55) grade = "D";
  else if (marks >= 45) grade = "E";
  else grade = "F";

  // Add student to list
  students.push({ id: ++studentCount, name, marks, grade });

  // Reset form
  document.getElementById("marksForm").reset();

  // Update table
  renderTable();
});

function renderTable() {
  const tableBody = document.getElementById("studentData");
  tableBody.innerHTML = "";

  students.forEach((student) => {
    const row = `
      <tr>
        <td>${student.id}</td>
        <td>${student.name}</td>
        <td>${student.marks}</td>
        <td>${student.grade}</td>
        <td>
          <button class="action-btn" onclick="deleteStudent(${student.id})">Delete</button>
        </td>
      </tr>
    `;
    tableBody.innerHTML += row;
  });
}

function deleteStudent(id) {
  students = students.filter(student => student.id !== id);
  renderTable();
}

function logout() {
  alert("You have been logged out!");
  window.location.href = "index.html";
}
``