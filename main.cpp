#include <QGuiApplication>
#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QTimer>

class OpenGLWindow : public QOpenGLWindow
{
public:
    void paintGL()
    {
        context()->functions()->glClearColor(qrand() / float(RAND_MAX),
                                             qrand() / float(RAND_MAX),
                                             qrand() / float(RAND_MAX),
                                             1.f);
        context()->functions()->glClear(GL_COLOR_BUFFER_BIT);
    }
};

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    OpenGLWindow w;
    w.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &w, QOverload<>::of(&QOpenGLWindow::update));
    timer.setSingleShot(false);
    timer.start(1000);

    MessageBox(
            HWND(w.winId()), (LPCWSTR)L"TEXT", (LPCWSTR)L"CAPTION", MB_ICONINFORMATION);

    return a.exec();
}
