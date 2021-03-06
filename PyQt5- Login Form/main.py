# -*- coding: utf-8 -*-

from PyQt5 import QtCore, QtGui, QtWidgets
import sqlite3


class Ui_MainWindow(object):

    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setMinimumSize(QtCore.QSize(800, 600))
        MainWindow.setMaximumSize(QtCore.QSize(800, 600))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.centralwidget.sizePolicy().hasHeightForWidth())
        self.centralwidget.setSizePolicy(sizePolicy)
        self.centralwidget.setObjectName("centralwidget")
        self.bg_photo = QtWidgets.QLabel(self.centralwidget)
        self.bg_photo.setGeometry(QtCore.QRect(0, 0, 800, 600))
        self.bg_photo.setAutoFillBackground(False)
        self.bg_photo.setText("")
        self.bg_photo.setPixmap(QtGui.QPixmap("imgs/bg.jpg"))
        self.bg_photo.setScaledContents(True)
        self.bg_photo.setObjectName("bg_photo")
        self.stackedWidget = QtWidgets.QStackedWidget(self.centralwidget)
        self.stackedWidget.setGeometry(QtCore.QRect(110, 50, 511, 411))
        self.stackedWidget.setObjectName("stackedWidget")
        self.page_register = QtWidgets.QWidget()
        self.page_register.setStyleSheet("*{\n"
                                         "font: italic 16pt \"Brush Script MT\";\n"
                                         "color : brown;\n"
                                         "background: transparent\n"
                                         "}\n"
                                         "\n"
                                         "QPushButton\n"
                                         "\n"
                                         "{\n"
                                         "background-color : rgb(85, 0, 0, 0.7);\n"
                                         "}\n"
                                         "\n"
                                         "QLabel\n"
                                         "{\n"
                                         "color: yellow\n"
                                         "}\n"
                                         "\n"
                                         "QLineEdit{\n"
                                         "background-color : rgb(85, 0, 0, 0.7);\n"
                                         "color:blue;\n"
                                         "}")
        self.page_register.setObjectName("page_register")
        self.formLayoutWidget = QtWidgets.QWidget(self.page_register)
        self.formLayoutWidget.setGeometry(QtCore.QRect(10, 150, 481, 191))
        self.formLayoutWidget.setObjectName("formLayoutWidget")
        self.formLayout = QtWidgets.QFormLayout(self.formLayoutWidget)
        self.formLayout.setContentsMargins(0, 0, 0, 0)
        self.formLayout.setObjectName("formLayout")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout()
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.register_name = QtWidgets.QLineEdit(self.formLayoutWidget)
        self.register_name.setObjectName("register_name")
        self.verticalLayout_4.addWidget(self.register_name)
        self.register_password = QtWidgets.QLineEdit(self.formLayoutWidget)
        self.register_password.setObjectName("register_password")
        self.register_password.setEchoMode(QtWidgets.QLineEdit.Password)
        self.verticalLayout_4.addWidget(self.register_password)
        self.register_confirm_password = QtWidgets.QLineEdit(self.formLayoutWidget)
        self.register_confirm_password.setObjectName("register_confirm_password")
        self.register_confirm_password.setEchoMode(QtWidgets.QLineEdit.Password)
        self.verticalLayout_4.addWidget(self.register_confirm_password)
        self.formLayout.setLayout(0, QtWidgets.QFormLayout.FieldRole, self.verticalLayout_4)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.label_3 = QtWidgets.QLabel(self.formLayoutWidget)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_3.addWidget(self.label_3)
        self.label_4 = QtWidgets.QLabel(self.formLayoutWidget)
        self.label_4.setObjectName("label_4")
        self.verticalLayout_3.addWidget(self.label_4)
        self.label_5 = QtWidgets.QLabel(self.formLayoutWidget)
        self.label_5.setObjectName("label_5")
        self.verticalLayout_3.addWidget(self.label_5)
        self.formLayout.setLayout(0, QtWidgets.QFormLayout.LabelRole, self.verticalLayout_3)
        self.registerButton = QtWidgets.QPushButton(self.formLayoutWidget)
        self.registerButton.setStyleSheet("")
        self.registerButton.setObjectName("registerButton")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.registerButton)
        self.stackedWidget.addWidget(self.page_register)
        self.page_login = QtWidgets.QWidget()
        self.page_login.setStyleSheet("*{\n"
                                      "font: italic 16pt \"Brush Script MT\";\n"
                                      "color : brown;\n"
                                      "background: transparent\n"
                                      "}\n"
                                      "\n"
                                      "QPushButton\n"
                                      "\n"
                                      "{\n"
                                      "background-color : rgb(85, 0, 0, 0.7);\n"
                                      "}\n"
                                      "\n"
                                      "QLabel\n"
                                      "{\n"
                                      "color: yellow\n"
                                      "}\n"
                                      "\n"
                                      "QLineEdit{\n"
                                      "background-color : rgb(85, 0, 0, 0.7);\n"
                                      "color:blue;\n"
                                      "}")
        self.page_login.setObjectName("page_login")
        self.frame = QtWidgets.QFrame(self.page_login)
        self.frame.setGeometry(QtCore.QRect(10, 10, 491, 391))
        self.frame.setStyleSheet("")
        self.frame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setObjectName("frame")
        self.login_button = QtWidgets.QPushButton(self.frame)
        self.login_button.setGeometry(QtCore.QRect(70, 290, 161, 51))
        self.login_button.setStyleSheet("")
        self.login_button.setObjectName("login_button")
        self.to_register_button = QtWidgets.QPushButton(self.frame)
        self.to_register_button.setGeometry(QtCore.QRect(260, 290, 161, 51))
        self.to_register_button.setStyleSheet("")
        self.to_register_button.setObjectName("to_register_button")
        self.verticalLayoutWidget = QtWidgets.QWidget(self.frame)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(30, 70, 181, 141))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.label_2 = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.label_2.setStyleSheet("")
        self.label_2.setAlignment(QtCore.Qt.AlignRight | QtCore.Qt.AlignTrailing | QtCore.Qt.AlignVCenter)
        self.label_2.setObjectName("label_2")
        self.verticalLayout.addWidget(self.label_2)
        self.label = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.label.setStyleSheet("")
        self.label.setAlignment(QtCore.Qt.AlignRight | QtCore.Qt.AlignTrailing | QtCore.Qt.AlignVCenter)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.verticalLayoutWidget_2 = QtWidgets.QWidget(self.frame)
        self.verticalLayoutWidget_2.setGeometry(QtCore.QRect(220, 70, 211, 151))
        self.verticalLayoutWidget_2.setObjectName("verticalLayoutWidget_2")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_2)
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.login_name = QtWidgets.QLineEdit(self.verticalLayoutWidget_2)
        self.login_name.setStyleSheet("")
        self.login_name.setObjectName("login_name")
        self.verticalLayout_2.addWidget(self.login_name)
        self.login_password = QtWidgets.QLineEdit(self.verticalLayoutWidget_2)
        self.login_password.setStyleSheet("")
        self.login_password.setObjectName("login_password")
        self.login_password.setEchoMode(QtWidgets.QLineEdit.Password)
        self.verticalLayout_2.addWidget(self.login_password)
        self.stackedWidget.addWidget(self.page_login)
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        self.stackedWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        # sayfalar arası geçiş -->
        self.to_register_button.clicked.connect(self.to_register_page)
        self.registerButton.clicked.connect(self.to_home_page)
        self.login_button.clicked.connect(self.check_info)

        conn = sqlite3.connect("data.db")
        cursor = conn.cursor()

        cursor.execute(
            "CREATE TABLE IF NOT EXISTS USERS(ID INTEGER NOT NULL PRIMARY KEY, USERNAME TEXT, PASSWORD TEXT)")
        conn.close()

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label_3.setText(_translate("MainWindow", "Username: "))
        self.label_4.setText(_translate("MainWindow", "Password:"))
        self.label_5.setText(_translate("MainWindow", "Confirm Password:"))
        self.registerButton.setText(_translate("MainWindow", "register"))
        self.login_button.setText(_translate("MainWindow", "login"))
        self.to_register_button.setText(_translate("MainWindow", "register"))
        self.label_2.setText(_translate("MainWindow", "USERNAME :"))
        self.label.setText(_translate("MainWindow", "PASSWORD :"))

    def to_register_page(self):
        self.stackedWidget.setCurrentIndex(0)

    def check_username(self, username):
        conn = sqlite3.connect("data.db")
        curr = conn.cursor()
        curr.execute("SELECT USERNAME FROM USERS")
        usernames = curr.fetchall()
        conn.close()
        for name in usernames:
            if username == name[0]:
                return False
        return True

    def to_home_page(self):
        _translate = QtCore.QCoreApplication.translate
        if self.register_name.text() == "" or self.register_password.text() == "" or self.register_confirm_password.text() == "":
            msg = QtWidgets.QMessageBox()
            msg.setText(_translate("MainWindow", "You must fill all lines !!!"))
            msg.setIcon(QtWidgets.QMessageBox.Warning)
            x = msg.exec_()
        elif self.register_password.text() != self.register_confirm_password.text():
            msg = QtWidgets.QMessageBox()
            msg.setText(_translate("MainWindow", "Passwords didn't match !!!"))
            msg.setIcon(QtWidgets.QMessageBox.Warning)
            x = msg.exec_()
        elif not self.check_username(self.register_name.text()):
            msg = QtWidgets.QMessageBox()
            msg.setText(_translate("MainWindow", "Username already taken !!!"))
            msg.setIcon(QtWidgets.QMessageBox.Warning)
            x = msg.exec_()
        else:
            conn = sqlite3.connect("data.db")
            conn.execute("INSERT INTO USERS(USERNAME,PASSWORD) values(?,?)",
                         (self.register_name.text(), self.register_password.text(),))
            conn.commit()
            conn.close()
            self.stackedWidget.setCurrentIndex(1)

    def check_info(self):
        _translate = QtCore.QCoreApplication.translate
        conn = sqlite3.connect("data.db")
        curr = conn.cursor()
        curr.execute("SELECT * FROM USERS")
        user_list = curr.fetchall()
        print(user_list)

        conn.close()
        flag = False
        for item in user_list:
            if item[1] == self.login_name.text() and item[2] == self.login_password.text():
                msg = QtWidgets.QMessageBox()
                msg.setWindowTitle(_translate("Login", "Logged in"))
                msg.setText(_translate("Login", "Login succesfull :)"))
                x = msg.exec_()
                flag = True
                break
        if not flag:
            msg = QtWidgets.QMessageBox()
            msg.setText(_translate("Login", "Username and pasword didn't match !!!"))
            msg.setIcon(QtWidgets.QMessageBox.Warning)
            msg.setWindowTitle(_translate("Login", "Login Error"))
            x = msg.exec_()
        else:
            exit()


if __name__ == "__main__":
    import sys

    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()

    list = ["Türkçe", "English"]
    t = QtCore.QTranslator()
    lang = QtWidgets.QInputDialog.getItem(MainWindow, "Select Language", "Language:", list)
    #print(lang)
    if lang[0] == "Türkçe":
        t.load("turkish.qm")
        app.installTranslator(t)

    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
