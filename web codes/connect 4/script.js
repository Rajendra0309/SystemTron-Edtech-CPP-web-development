// script.js

const ROWS = 6;
const COLS = 7;
let currentPlayer = 1;
let board = [];
let gameActive = true;

const gameBoard = document.getElementById('gameBoard');
const message = document.getElementById('message');
const resetButton = document.getElementById('resetButton');

resetButton.addEventListener('click', resetGame);

function createBoard() {
    board = [];
    gameBoard.innerHTML = '';
    for (let row = 0; row < ROWS; row++) {
        const rowArray = [];
        for (let col = 0; col < COLS; col++) {
            const cell = document.createElement('div');
            cell.classList.add('cell');
            cell.dataset.row = row;
            cell.dataset.col = col;
            cell.addEventListener('click', handleCellClick);
            gameBoard.appendChild(cell);
            rowArray.push(null);
        }
        board.push(rowArray);
    }
}

function handleCellClick(event) {
    if (!gameActive) return;

    const col = parseInt(event.target.dataset.col);
    for (let row = ROWS - 1; row >= 0; row--) {
        if (!board[row][col]) {
            board[row][col] = currentPlayer;
            const cell = document.querySelector(`.cell[data-row="${row}"][data-col="${col}"]`);
            cell.classList.add(`player${currentPlayer}`);
            const winningCells = checkWin(row, col);
            if (winningCells) {
                highlightWinningCells(winningCells);
                message.textContent = `Player ${currentPlayer} wins!`;
                gameActive = false;
                return;
            }
            if (isBoardFull()) {
                message.textContent = "It's a tie!";
                gameActive = false;
                return;
            }
            currentPlayer = currentPlayer === 1 ? 2 : 1;
            message.textContent = `Player ${currentPlayer}'s turn`;
            return;
        }
    }
}

function checkWin(row, col) {
    return checkDirection(row, col, 1, 0) || // Horizontal
           checkDirection(row, col, 0, 1) || // Vertical
           checkDirection(row, col, 1, 1) || // Diagonal down-right
           checkDirection(row, col, 1, -1);  // Diagonal down-left
}

function checkDirection(row, col, rowDir, colDir) {
    let count = 1;
    let winningCells = [[row, col]];

    for (let i = 1; i < 4; i++) {
        const r = row + i * rowDir;
        const c = col + i * colDir;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] !== currentPlayer) break;
        count++;
        winningCells.push([r, c]);
    }
    for (let i = 1; i < 4; i++) {
        const r = row - i * rowDir;
        const c = col - i * colDir;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] !== currentPlayer) break;
        count++;
        winningCells.push([r, c]);
    }
    return count >= 4 ? winningCells : null;
}

function highlightWinningCells(winningCells) {
    winningCells.forEach(([row, col]) => {
        const cell = document.querySelector(`.cell[data-row="${row}"][data-col="${col}"]`);
        cell.classList.add('winner');
    });
}

function isBoardFull() {
    for (let col = 0; col < COLS; col++) {
        if (board[0][col] === null) return false;
    }
    return true;
}

function resetGame() {
    currentPlayer = 1;
    gameActive = true;
    message.textContent = `Player ${currentPlayer}'s turn`;
    createBoard();
}

resetGame();
