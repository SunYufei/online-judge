groupadd testuser
useradd -g testuser zhangsan
passwd zhangsan
useradd -g testuser lisi
passwd lisi
mkdir /home/test
chown zhangsan:testuser /home/test
chmod 764 /home/test