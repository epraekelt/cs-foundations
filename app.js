const pug = require('pug');
const fs = require('fs');
const path = require('path');

function renderFolder(srcFolder, destFolder) {
  fs.readdir(srcFolder, (err, files) => {
    if (err) return console.error(err);

    files.forEach(f => {
      const file = path.join(srcFolder, f);
      const dest = path.join(destFolder, f);
      if (fs.statSync(file).isDirectory()) {
        return fs.mkdir(dest, (err) => {
          renderFolder(file, dest);
        });
      }

      fs.writeFile(
        dest.replace(/\.pug$/, '.html'), 
        pug.renderFile(file, {
          error: {},
        }), 
        (err) => {
          if (err) return console.error(err);
        }
      );
    });
  });
}

renderFolder(path.join(__dirname, 'views'), __dirname);
