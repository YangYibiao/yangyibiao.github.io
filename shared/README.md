# shared

`cpp/`、`cpl/`、`datamining/` 共用的 Reveal.js 资源，避免每个课程目录各存一份。

## 目录

- `css/`、`fonts/`、`js/`、`plugin/`、`mermaid/`、`vega/`、`dot/`、`puml/`
- `revealjs_deps/`：公共 `notes.js` / `notes.html`；旧版 notes 为 `notes-legacy.js`

## 引用约定

课程页面使用**相对路径**引用，保持 `file://` 本地预览可用：

- `cpl/index.html` → `../shared/css/main.css`
- `cpl/slides/11-pointers/x.html` → `../../../shared/css/main.css`
- `cpp/slides/01-topic/x.html` → `../../../shared/css/main.css`
- `datamining/slides/x.html` → `../../shared/css/main.css`

不要再把 `css/`、`fonts/`、`plugin/` 等复制回课程目录。`datamining/css/main.css`、`datamining.css` 是课程覆盖，保留在课程目录；`datamining/slides/revealjs_deps/` 是 datamining 专用 bundle，也保留。
