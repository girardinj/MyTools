@echo off

SET "PYTHON_FILE_LOCATION=C:\MyTools"

pandoc --version
IF ERRORLEVEL 1 (
  echo.
  echo you have to install pandoc first, visit https://pandoc.org/ for more information
  exit /B
)

IF NOT EXIST md (
  echo.
  echo no file named md found, you have to put your .md ^(with this extension precisely^) in a md folder
  exit /B
)
IF NOT EXIST html (mkdir html)
IF NOT EXIST temp (mkdir temp)

python %PYTHON_FILE_LOCATION%\change_link_of_md_to_html.py %cd% md
for /F usebackq %%G IN (`dir /a-d /b .\temp`) DO (pandoc .\temp\%%G -f markdown -t html -s -o .\html\%%~nG.html --quiet)
echo o | rmdir /s temp

echo @echo off > index.bat
echo echo. >> index.bat
echo echo last time modified is %DATE% at %TIME% >> index.bat
echo html\index.html >> index.bat