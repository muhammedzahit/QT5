from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from random import randint
import sys


class Counter(QWidget):
    def __init__(self):
        super().__init__()
        style_file = QFile("style.css")
        style_file.open(QIODevice.ReadOnly | QIODevice.Text)
        stream = QTextStream(style_file)
        self.styleSheet = stream.readAll()
        self.setStyleSheet(self.styleSheet)
        self.kare_durumu = []
        for i in range(3):
            self.kare_durumu.append([])
            for j in range(3):
                self.kare_durumu[i].append("?")
        self.aktif_kare = [0, 0]

        self.show()

    def paintEvent(self, a0: QPaintEvent) -> None:

        painter = QPainter(self)
        for i in range(3):
            for j in range(3):
                if self.kare_durumu[i][j] != "?":
                    path = self.kare_durumu[i][j] + ".png"
                    painter.drawImage(QRect((self.width() / 3) * i, (self.height() / 3)
                                            * j, self.width() / 3, self.height() / 3), QImage(path))

        for i in range(1, 3):
            painter.drawLine(0, int(self.height() / 3 * i),
                             self.width(), (self.height() / 3) * i)
        for i in range(1, 3):
            painter.drawLine(int(self.width() / 3) * i, 0,
                             (self.width() / 3) * i, self.height())

        pen = QPen()
        pen.setBrush(Qt.blue)
        pen.setWidth(3)
        painter.setPen(pen)

        a = self.aktif_kare[0]
        b = self.aktif_kare[1]
        b2 = b
        if (b2 == 2):
            b2 = 1
        painter.drawLine(int(self.width() / 3) * a, int(self.height() / 3) * (b2+1),
                         int(self.width() / 3) * (a+1), int(self.height() / 3) * (b2+1))
        if (a == 2):
            a = 1
        painter.drawLine(self.width() / 3 * (a+1), self.height() / 3 * (b),
                         self.width() / 3 * (a+1), self.height() / 3 * (b+1))
        painter.end()
        return super().paintEvent(a0)

    def control(self, control_num):
        if control_num < 0:
            return 0
        elif control_num > 2:
            return 2
        return control_num

    def oyun_bitti_mi(self):
        for i in range(3):
            for j in range(3):
                if self.kare_durumu[i][j] == "?":
                    return False
        return True

    def bilgisayar_hamlesi(self):
        x = randint(0, 2)
        y = randint(0, 2)
        while(self.kare_durumu[x][y] != "?"):
            x = randint(0, 2)
            y = randint(0, 2)
        self.kare_durumu[x][y] = "com"

    def kazandi_mi(self):
        for x in range(3):
            if self.kare_durumu[x][0] != "?" and self.kare_durumu[x][0] == self.kare_durumu[x][1] \
                    and self.kare_durumu[x][1] == self.kare_durumu[x][2]:
                return self.kare_durumu[x][0]
        for y in range(3):
            if self.kare_durumu[0][y] != "?" and self.kare_durumu[0][y] == self.kare_durumu[1][y] \
                    and self.kare_durumu[1][y] == self.kare_durumu[2][y]:
                return self.kare_durumu[0][y]

        if self.kare_durumu[0][0] != "?" and self.kare_durumu[0][0] == self.kare_durumu[1][1] \
                and self.kare_durumu[1][1] == self.kare_durumu[2][2]:
            return self.kare_durumu[0][0]

        if self.kare_durumu[0][2] != "?" and self.kare_durumu[0][2] == self.kare_durumu[1][1] \
                and self.kare_durumu[1][1] == self.kare_durumu[2][0]:
            return self.kare_durumu[0][2]

        return None

    def keyPressEvent(self, a0: QKeyEvent) -> None:

        if (a0.key() == Qt.Key_Up):
            self.aktif_kare[1] -= 1
        elif (a0.key() == Qt.Key_Down):
            self.aktif_kare[1] += 1
        elif (a0.key() == Qt.Key_Left):
            self.aktif_kare[0] -= 1
        elif (a0.key() == Qt.Key_Right):
            self.aktif_kare[0] += 1
        elif (a0.key() == Qt.Key_Enter):
            self.kare_durumu[self.aktif_kare[0]][self.aktif_kare[1]] = "user"
            if(self.kazandi_mi() is not None):
                box = QMessageBox(self)
                box.setText("You won the game!!!")
                box.exec_()
                self.close()
                return
            if(self.oyun_bitti_mi()):
                box = QMessageBox(self)
                box.setText("Draw!!!")
                box.exec_()
                self.close()
                return
            self.bilgisayar_hamlesi()
            if(self.kazandi_mi() is not None):
                box = QMessageBox(self)
                box.setText("Computer won the game!!!")
                box.exec_()
                self.close()
                return
            if(self.oyun_bitti_mi()):
                box = QMessageBox(self)
                box.setText("Draw!!!")
                box.exec_()
                self.close()
                return
        self.aktif_kare[0] = self.control(self.aktif_kare[0])
        self.aktif_kare[1] = self.control(self.aktif_kare[1])
        self.update()
        return super().keyPressEvent(a0)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    widget = Counter()
    sys.exit(app.exec_())
