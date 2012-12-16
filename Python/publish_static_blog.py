from ftplib import FTP
ftp = FTP()
timeout = 30
port = 21
ftp.connect('174.36.161.146', port, timeout)
ftp.login('hoolg', '111111111')
print ftp.getwelcome()
ftp.cwd('public_html')
ftp.storbinary('STOR index.html', open('E:\Think anyway\static_blog\index.html','rb'))
#ftp.delete('index.html')
ftp.quit()
