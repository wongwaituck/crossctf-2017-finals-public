FROM ubuntu:latest
RUN apt-get update
RUN apt-get install -y xinetd lib32z1 gcc-multilib build-essential
ENV user=skypillaruser
RUN useradd -m $user
RUN echo "$user     hard    nproc       20" >> /etc/security/limits.conf
COPY ./main.c /home/skypillaruser/skypillar/
COPY ./Makefile /home/skypillaruser/skypillar/
COPY ./skypillarservice /etc/xinetd.d/skypillarservice
RUN set -ex \
    && cd /home/skypillaruser/skypillar \
    && make
RUN chown -R root:skypillaruser /home/skypillaruser
RUN chmod -R 750 /home/skypillaruser
EXPOSE 31337
CMD ["/usr/sbin/xinetd", "-d"]
