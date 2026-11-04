/* hanoi-anim.js: 汉诺塔 3 盘 7 步动画逻辑 (由 9-2 课件的 "Hanoi 塔 · 盘子动画" 页加载) */
(function () {
  var pegs = [[3, 2, 1], [], []];
  var moves = [[0, 2], [0, 1], [2, 1], [0, 2], [1, 0], [1, 2], [0, 2]];
  var step = 0, timer = null;
  var ids = { 3: 'h3', 2: 'h2', 1: 'h1' };

  function place(d) {
    var peg = -1, h = 0;
    for (var p = 0; p < 3; p++) {
      var i = pegs[p].indexOf(d);
      if (i >= 0) { peg = p; h = i; }
    }
    var el = document.getElementById(ids[d]);
    if (!el) return;
    el.style.transition = 'transform 0.5s ease-in-out';
    el.style.transform = 'translate(' + (150 + peg * 150) + 'px,' + (246 - h * 24) + 'px)';
  }

  function msg(t) {
    var m = document.getElementById('hanoiMsg');
    if (m) m.textContent = t;
  }

  function stepInfo() {
    var s = document.getElementById('hanoiStep');
    if (s) s.textContent = step + ' / 7';
  }

  window.hanoiNext = function () {
    if (step >= moves.length) { msg('✓ 完成! 3 个盘已全部移到 C (共 7 步)'); return; }
    var mv = moves[step];
    var d = pegs[mv[0]].pop();
    pegs[mv[1]].push(d);
    step++;
    place(d);
    msg('第 ' + step + ' 步: 盘 ' + d + ': ' + 'ABC'[mv[0]] + ' → ' + 'ABC'[mv[1]]);
    stepInfo();
  };

  window.hanoiAuto = function () {
    if (timer) { return; }
    window.hanoiReset();
    timer = setInterval(function () {
      if (step >= moves.length) { clearInterval(timer); timer = null; return; }
      window.hanoiNext();
    }, 900);
  };

  window.hanoiReset = function () {
    if (timer) { clearInterval(timer); timer = null; }
    pegs = [[3, 2, 1], [], []];
    step = 0;
    [3, 2, 1].forEach(place);
    msg('初始状态: 3 个盘都在 A');
    stepInfo();
  };

  if (document.readyState === 'complete') { window.hanoiReset(); }
  else { window.addEventListener('load', window.hanoiReset); }
})();
