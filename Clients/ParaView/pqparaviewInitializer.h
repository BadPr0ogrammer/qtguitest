// ***************** DO NOT EDIT ***********************************
// This is a generated file.
// It will be replaced next time you rebuild.
#ifndef pqparaviewInitializer_h
#define pqparaviewInitializer_h

class QMainWindow;
class pqPVApplicationCore;
class QSplashScreen;

class pqparaviewInitializer
{
public:
  enum Status
  {
    ExitSuccess,
    ExitFailure,
    RunApplication
  };

  pqparaviewInitializer();
  ~pqparaviewInitializer();

  /// Initialize ParaView. It returns false if the initialization failed.
  Status Initialize(int argc, char* argv[]);
private:
  pqPVApplicationCore* PVApp;
  QMainWindow* MainWindow;
  QSplashScreen* Splash;
};

#endif
