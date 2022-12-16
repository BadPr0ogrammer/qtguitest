#include "pqPythonUndoCommand2.h"
// b #include "pqPythonSyntaxHighlighter.h"

//-----------------------------------------------------------------------------
pqPythonUndoCommand::pqPythonUndoCommand(QTextEdit& text, 
    // b pqPythonSyntaxHighlighter* highlighter,
  pqPythonTextHistoryEntry& lastHistoryEntry, const pqPythonTextHistoryEntry&& currentHistoryEntry)
  : Text(text)
  // b , Highlighter(highlighter)
  , TextLastHystoryEntry(lastHistoryEntry)
  , LastHistoryEntry(lastHistoryEntry)
  , CurrentHistoryEntry(currentHistoryEntry)
{
}

//-----------------------------------------------------------------------------
void pqPythonUndoCommand::swapImpl(const pqPythonTextHistoryEntry& h)
{
  // We block all text signals (this is done to avoid pushing twice
  // the text in the undo stack)
  const bool oldState = this->Text.blockSignals(true);
  /* b
  const QString highlightedText = this->Highlighter->Highlight(h.content);
  if (!highlightedText.isEmpty())
  {
    this->Text.setHtml(highlightedText);
  }
  else
  */
  {
    this->Text.setText(h.content);
  }

  // Move the cursor
  if (!h.isEmpty())
  {
    QTextCursor cursor = this->Text.textCursor();
    cursor.setPosition(h.cursorPosition);
    this->Text.setTextCursor(cursor);
  }

  // re-enable the signals
  this->Text.blockSignals(oldState);
};

//-----------------------------------------------------------------------------
void pqPythonUndoCommand::undo()
{
  this->swapImpl(this->LastHistoryEntry);
  this->TextLastHystoryEntry = this->LastHistoryEntry;
  this->Text.document()->setModified(true);
}

//-----------------------------------------------------------------------------
void pqPythonUndoCommand::redo()
{
  this->swapImpl(this->CurrentHistoryEntry);
  this->Text.document()->setModified(true);
}
