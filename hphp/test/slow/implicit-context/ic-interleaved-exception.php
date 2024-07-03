<?hh

function throwExn(): mixed {
  throw new Exception();
}

function printMSIC(): void {
  try {
    var_dump(MemoSensitiveIntCtx::getContext());
  } catch (InvalidOperationException $e) {
    echo $e->getMessage()."\n";
  }
}

function printMAIC(): void {
  try {
    var_dump(MemoAgnosticIntCtx::getContext());
  } catch (InvalidOperationException $e) {
    echo $e->getMessage()."\n";
  }
}


<<__EntryPoint>>
function main(): mixed{
  include 'both-contexts.inc';
  try {
    MemoSensitiveIntCtx::start(1, () ==> {
      try {
        MemoAgnosticIntCtx::runWith(2, () ==> {
          printMAIC(); // should return 2
          printMSIC(); // should return 1
          throwExn();
        });
      } catch (Exception $e) {
        var_dump('caught!');
        printMAIC(); // should return NULL
        printMSIC(); // should still return 1
        throwExn();
      }
    });
  } catch (Exception $e) {
    var_dump('caught outer!');
    printMAIC(); // should return NULL
    printMSIC(); // should throw
  }

  try {
    MemoAgnosticIntCtx::runWith(1, () ==> {
    try {
      MemoSensitiveIntCtx::start(2, () ==> {
        printMAIC(); // should return 1, set on the outer
        printMSIC(); // should return 2
        throwExn();
      });
    } catch (Exception $e) {
      var_dump('caught!');
      printMAIC(); // should return 1 still
      printMSIC(); // should throw
      throwExn();
    }
  });
  } catch (Exception $e) {
    var_dump('caught outer!');
    printMAIC(); // should return NULL
    printMSIC(); // should throw
  }
}
