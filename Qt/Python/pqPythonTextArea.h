#ifndef pqPythonTextArea_h
#define pqPythonTextArea_h

#include "pqPythonModule.h"

#include "pqPythonEditorActions2.h"
#include "pqPythonUndoCommand2.h"
#include "pqPythonUtils2.h"
// b #include "pqTextLinkerPython.h"

#include <QKeyEvent>
#include <QUndoStack>
#include <QWidget>

// b class pqPythonSyntaxHighlighter;
class pqPythonFileIO;
class pqPythonLineNumberArea;
class QTextEdit;

/**
 * @class pqPythonTextArea
 * @brief A python text editor widget
 * @details Displays an editable text area with syntax
 * python highlighting and line numbering.
 */
class PQPYTHON_EXPORT pqPythonTextArea : public QWidget
{
  Q_OBJECT

public:
  /**
   * @brief Construct a pqPythonTextArea
   * @input[parent] the parent widget for the Qt ownership
   */
  explicit pqPythonTextArea(QWidget* parent);

  /**
   * @brief Returns the underlying \ref TextEdit
   */
  const QTextEdit* getTextEdit() const { return this->TextEdit; }

  /**
   * @brief Returns the underlying \ref TextEdit
   */
  QTextEdit* getTextEdit() { return this->TextEdit; }

  // b const QUndoStack& getUndoStack() const { return this->UndoStack; }

  /**
   * @brief Returns true if the file has been saved
   */
  bool saveOnClose();

  /**
   * @brief Opens a file in the editor.
   * Triggers a saving wizard if the current buffer
   * has not beed saved on the disk.
   */
  bool openFile(const QString& filename);

  /**
   * @brief Sets the default save directory.
   * Only used for the directory displayed
   * when the save popup window is shown.
   */
  void setDefaultSaveDirectory(const QString& dir);

  /**
   * @brief Connects this widget to the set of actions
   */
  void connectActions(pqPythonEditorActions& actions);

  /**
   * @brief Disconnect this widget from the set of actions
   */
  void disconnectActions(pqPythonEditorActions& actions);

  /**
   * @brief Get filename associated with this buffer.
   * Returns an empty string if no file is associated.
   */
  const QString& getFilename() const;

  /**
   * @brief Returns true if the buffer is empty
   */
  bool isEmpty() const;

  /**
   * @brief Returns true if the buffer has been modified
   * but not saved
   */
  bool isDirty() const;

  /**
   * @brief Override the current buffer content
   * with the referenced string
   */
  void setText(const QString& text);

  /**
   * @brief Link the current text area
   * to an arbitrary QTextEdit like
   * object
   */
  /* b
  template <typename T>
  void linkTo(T* /*obj)
  {
    static_assert(sizeof(T) == 0, "Only specializations of linkTo(T* t) can be used");
  }
  */
  /**
   * @brief Removes the linked QTextEdit like object

  void unlink();
  */
  /**
   * @brief Returns true if the parameter is linked
   * to this text area
   */
  // b bool isLinkedTo(const QObject* obj) const { return this->TextLinker.isLinkedTo(obj); }

  /**
   * @brief Returns true if this text area is linked
   */
   // b bool isLinked() const { return this->TextLinker.isLinked(); }

  /**
   * @brief Returns the linked text name. Returns an empty string
   * if nothing is linked
   */
   // b QString getLinkedName() const { return this->TextLinker.getSecondObjectName(); }

Q_SIGNALS:
  /**
   * @brief Triggered when the current text
   * buffer is erased
   */
  void bufferErased();

  /**
   * @brief Triggers after a file has been
   * successfuly opened in the current buffer.
   */
  void fileOpened(const QString&);

  /**
   * @brief Triggers after a successful
   * saves of the current buffer.
   */
  void fileSaved(const QString&);

  /**
   * @brief Emitted when the buffer content
   * has been modified.
   */
  void contentChanged();

protected:
  /**
   * @brief Filter the KeyEvent CTRL+Z
   * @details We need to filter the QTextEdit KeyEvent
   * otherwise our undo/redo actions are not triggered.
   */
  bool eventFilter(QObject* obj, QEvent* event) override;

private:
  void setupActions();

  void setupMenus();

  /**
   * @brief The editable text area
   */
  QPointer<QTextEdit> TextEdit;

  /**
   * @brief The line number area widget
   */
  QPointer<pqPythonLineNumberArea> LineNumberArea;

  /**
   * @brief The syntax highlighter used to color the \ref TextEdit
   */
  // b QPointer<pqPythonSyntaxHighlighter> SyntaxHighlighter;

  /**
   * @brief The IO module used to save the \ref TextEdit
   */
  QPointer<pqPythonFileIO> FileIO;

  // b pqTextLinker TextLinker;

  /**
   * @brief The text QUndoStack
   */
  // b QUndoStack UndoStack;

  /**
   * @brief The last history entry in the undo stack
   * @details Unfortunatly, QTextEdit doesn't keep
   * a text hystory, which we need for the \ref UndoStack.
   */
  pqPythonTextHistoryEntry lastEntry;
};

#include "pqPythonTextArea.txx"

#endif // pqPythonTextArea_h
