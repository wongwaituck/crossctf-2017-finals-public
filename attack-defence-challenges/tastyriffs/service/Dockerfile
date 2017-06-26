FROM ubuntu:latest
ENV user=tastyriffs
RUN dpkg --add-architecture i386
RUN sed -i -e 's/archive\.ubuntu\.com/mirror\.0x\.sg/g' /etc/apt/sources.list
RUN apt-get update
RUN apt-get install -y xinetd libc6:i386 libncurses5:i386 libstdc++6:i386 python2.7
RUN useradd -m $user
RUN useradd -m greatest
RUN echo "$user     hard    nproc       20" >> /etc/security/limits.conf
COPY ./greatest.py /
COPY ./tastyservice /etc/xinetd.d/tastyservice
COPY ./flag /home/$user/flag
COPY ./bin/tastyriffs /bin/tastyriffs
COPY ./picpic /picpic
COPY ./helper /home/$user/helper
ADD ./profiles /profiles
RUN chown -R root:$user /home/$user
RUN chmod -R 755 /home/$user
RUN chown root:$user /home/$user/flag
RUN chmod 440 /home/$user/flag
RUN chown root:greatest /greatest.py
RUN chmod 440 /greatest.py
RUN chmod +x /greatest.py
RUN chown root:$user /bin/tastyriffs
RUN chmod +x /bin/tastyriffs
RUN chmod +x /home/$user/helper
RUN chmod +s /home/$user/helper
RUN chown root:greatest /picpic
RUN chmod 440 /picpic
RUN ln -s /usr/bin/python2.7 /usr/bin/python
EXPOSE 31337
CMD ["/usr/sbin/xinetd", "-d"]
