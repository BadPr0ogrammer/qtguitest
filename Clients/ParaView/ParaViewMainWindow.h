#ifndef ParaViewMainWindow_h
#define ParaViewMainWindow_h

#include <QMainWindow>

/// MainWindow for the default ParaView application.
class ParaViewMainWindow : public QMainWindow
{
  Q_OBJECT
  typedef QMainWindow Superclass;

public:
  ParaViewMainWindow();
  ~ParaViewMainWindow() override;

protected:
  /* b
  void dragEnterEvent(QDragEnterEvent* evt) override;
  void dropEvent(QDropEvent* evt) override;
  */
  void showEvent(QShowEvent* evt) override;
  void closeEvent(QCloseEvent* evt) override;

protected Q_SLOTS: // NOLINT(readability-redundant-access-specifiers)
  /* b 
  void showHelpForProxy(const QString& groupname, const QString& proxyname);
  void showWelcomeDialog();
  b void updateFontSize();
  */
  void handleMessage(const QString&, int);

private:
  Q_DISABLE_COPY(ParaViewMainWindow)

  class pqInternals;
  pqInternals* Internals;
};

#endif
