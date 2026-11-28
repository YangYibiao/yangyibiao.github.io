module.exports = {
  // onWillParseMarkdown: function (markdown) {
  //   return new Promise((resolve, reject) => {
  //     markdown = markdown.replace(
  //       /HEADER\s+([\w\W]*?)\n/gm,
  //       (whole, header) =>
  //         '<div class="header"><img class="hust"><div class="title"><hr class="hr_top"><h5>' +
  //         header +
  //         "</h5></div></div>\n"
  //     );
  //     markdown = markdown.replace(
  //       /FOOTER3\s+([\w\W]*?)\s+([\w\W]*?)\s+([\w\W]*?)\n/gm,
  //       (whole, footer1, footer2, footer3) =>
  //         '<div class="footer"><hr class="hr_bottom"><div class="multi_column"><h6 class="bottom_left">' +
  //         footer1 +
  //         '</h6><h6 class="bottom_center">' +
  //         footer2 +
  //         '</h6><h6 class="bottom_right">' +
  //         footer3 +
  //         "</h6></div></div>\n"
  //     );
  //     markdown = markdown.replace(
  //       /\$\$([\w\W]+?)\$\$\n/g,
  //       (whole, content) => '<p>\n$$' + content + '$$\n</p>\n'
  //     );
  //     markdown = markdown.replace(
  //       /我的批注/g,
  //       (whole, content) => '<span class="yellow">:fa-weixin:</span>'
  //     );
  //     markdown = markdown.replace(
  //       /我的启示/g,
  //       (whole, content) => '<span class="blue">:fa-lightbulb-o:</span>'
  //     );
  //     return resolve(markdown);
  //   });
  // },
  // onDidParseMarkdown: function (html) {
  //   return new Promise((resolve, reject) => {
  //     return resolve(html);
  //   });
  // },
  onWillParseMarkdown: function (markdown) {
  return new Promise((resolve, reject) => {
    markdown = markdown.replace(
      /HEADER\s+([\w\W]*?)\n/gm,
      (whole, header) =>
        '<div class="header"><img class="hust"><div class="title"><hr class="hr_top"><h5>' +
        header +
        "</h5></div></div>\n"
    );
    markdown = markdown.replace(
      /FOOTER3\s+([\w\W]*?)\s+([\w\W]*?)\s+([\w\W]*?)\n/gm,
      (whole, footer1, footer2, footer3) =>
        '<div class="footer"><hr class="hr_bottom"><div class="multi_column"><h6 class="bottom_left">' +
        footer1 +
        '</h6><h6 class="bottom_center">' +
        footer2 +
        '</h6><h6 class="bottom_right">' +
        footer3 +
        "</h6></div></div>\n"
    );
    markdown = markdown.replace(
      /\$\$([\w\W]+?)\$\$\n/g,
      (whole, content) => '<p>\n$$' + content + '$$\n</p>\n'
    );
    markdown = markdown.replace(
      /我的批注/g,
      (whole, content) => '<span class="yellow">:fa-weixin:</span>'
    );
    markdown = markdown.replace(
      /我的启示/g,
      (whole, content) => '<span class="blue">:fa-lightbulb-o:</span>'
    );
    // 添加的新规则：将 :fa-lightbulb-o: 替换为 <i> 标签
    markdown = markdown.replace(
      /:fa-lightbulb-o:/g,
      '<i class="fa fa-lightbulb-o"></i>'
    );
    // 同样地，如果您使用了其他图标，比如 :fa-weixin:，也需要添加类似规则
    markdown = markdown.replace(
      /:fa-weixin:/g,
      '<i class="fa fa-weixin"></i>'
    );
    return resolve(markdown);
  });
},
};
