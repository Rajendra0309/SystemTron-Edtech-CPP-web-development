document.addEventListener('DOMContentLoaded', () => {
    const form = document.getElementById('todo-form');
    const input = document.getElementById('new-todo');
    const todoList = document.getElementById('todo-list');

    form.addEventListener('submit', (event) => {
        event.preventDefault();
        addTodo(input.value);
        input.value = '';
        saveTodos();
    });

    function addTodo(task, completed = false) {
        const li = document.createElement('li');
        if (completed) {
            li.classList.add('completed');
        }

        const circle = document.createElement('div');
        circle.classList.add('circle');
        if (completed) {
            circle.classList.add('checked');
        }
        circle.addEventListener('click', () => {
            circle.classList.toggle('checked');
            li.classList.toggle('completed');
            saveTodos();
        });

        const taskSpan = document.createElement('span');
        taskSpan.textContent = task;
        taskSpan.classList.add('task-text');

        const deleteButton = document.createElement('button');
        deleteButton.textContent = '✖';
        deleteButton.classList.add('delete');
        deleteButton.addEventListener('click', () => {
            todoList.removeChild(li);
            saveTodos();
        });

        li.appendChild(circle);
        li.appendChild(taskSpan);
        li.appendChild(deleteButton);
        todoList.appendChild(li);
    }

    function saveTodos() {
        const todos = [];
        document.querySelectorAll('li').forEach(task => {
            const taskText = task.querySelector('.task-text').textContent;
            const completed = task.querySelector('.circle').classList.contains('checked');
            todos.push({ text: taskText, completed });
        });
        localStorage.setItem('todos', JSON.stringify(todos));
    }

    function loadTodos() {
        const todos = JSON.parse(localStorage.getItem('todos'));
        if (todos) {
            todos.forEach(todo => {
                addTodo(todo.text, todo.completed);
            });
        }
    }

    loadTodos();
});
