@rem mkdir ..\gajomi-build-desktop\debug\images
@rem xcopy images ..\gajomi-build-desktop\debug\images /S /Y
@rem mkdir ..\gajomi-build-desktop\debug\maps
@rem xcopy maps ..\gajomi-build-desktop\debug\maps /S /Y

mkdir ..\gajomi-bin\images
xcopy images ..\gajomi-bin\images /S /Y
mkdir ..\gajomi-bin\maps
xcopy maps ..\gajomi-bin\maps /S /Y
mkdir ..\gajomi-bin\sounds
xcopy sounds ..\gajomi-bin\sounds /S /Y
copy Levels.txt ..\gajomi-bin\Levels.txt 
copy FreeSerif.ttf ..\gajomi-bin\FreeSerif.ttf