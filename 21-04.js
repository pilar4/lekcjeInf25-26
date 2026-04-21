zad 1 w files, prezentacja o fraktalach gamma

zad2 html
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Generator Fraktali</title>
    <style>
        body {
            font-family: sans-serif;
            display: flex;
            flex-direction: column;
            align-items: center;
            background-color: #1a1a1a;
            color: white;
            padding: 20px;
        }
        canvas {
            border: 2px solid #444;
            background-color: #000;
            margin-top: 20px;
            box-shadow: 0 0 20px rgba(0,0,0,0.5);
        }
        .controls {
            background: #333;
            padding: 20px;
            border-radius: 8px;
            display: flex;
            gap: 15px;
            align-items: center;
        }
        button {
            padding: 10px 20px;
            cursor: pointer;
            background-color: #007bff;
            border: none;
            color: white;
            border-radius: 4px;
            font-weight: bold;
        }
        button:hover { background-color: #0056b3; }
    </style>
</head>
<body>

    <h1>Generator Drzewa Fraktalnego</h1>

    <div class="controls">
        <label for="level">Stopień fraktalu (1-12):</label>
        <input type="range" id="level" min="1" max="12" value="5">
        <span id="levelValue">5</span>
        <button id="drawBtn">Rysuj Fraktal</button>
    </div>

    <canvas id="fractalCanvas" width="800" height="600"></canvas>

    <script>
        const canvas = document.getElementById('fractalCanvas');
        const ctx = canvas.getContext('2d');
        const levelInput = document.getElementById('level');
        const levelValue = document.getElementById('levelValue');
        const drawBtn = document.getElementById('drawBtn');

        // Aktualizacja wyświetlanej wartości suwaka
        levelInput.oninput = () => levelValue.innerText = levelInput.value;

        function drawTree(startX, startY, len, angle, branchWidth, level) {
            ctx.beginPath();
            ctx.save();
            ctx.strokeStyle = `hsl(${level * 30}, 70%, 50%)`; // Kolor zależny od stopnia
            ctx.lineWidth = branchWidth;
            ctx.translate(startX, startY);
            ctx.rotate(angle * Math.PI / 180);
            ctx.moveTo(0, 0);
            ctx.lineTo(0, -len);
            ctx.stroke();

            // Jeśli nie osiągnęliśmy limitu rekurencji
            if (level > 0) {
                // Lewa gałąź
                drawTree(0, -len, len * 0.75, -25, branchWidth * 0.7, level - 1);
                // Prawa gałąź
                drawTree(0, -len, len * 0.75, 25, branchWidth * 0.7, level - 1);
            }

            ctx.restore();
        }

        function startDrawing() {
            // Czyszczenie płótna
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            
            const depth = parseInt(levelInput.value);
            // Uruchomienie rysowania od dołu na środku
            drawTree(canvas.width / 2, canvas.height - 50, 150, 0, 10, depth);
        }

        drawBtn.addEventListener('click', startDrawing);

        // Rysuj na starcie
        startDrawing();
    </script>
</body>
</html>
