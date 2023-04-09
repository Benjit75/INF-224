# INF224 Ternot Benjamin

## Run

As I did have the time to implement the GUI, my application consist on a client/server interaction.
First, you need to run `make all` in `/cpp` folder. It will compile and build `server`and `client`.
Then you need to launch `server` first, then `client` (eventually on 2 terminals).

You can then proceed to sen requests of type `PLAY + name`, `CREATE + type [+ args]` ( for example `CREATE Photo thename thepathname 1280 720`), `SEARCH + name`, `QUIT` from the client.

## Questions
### Etape 4
We cannot instantiate from base class because it contains a pure virtual function.

### Etape 5
In POO, the polymorphism and overriden of virtual functions allow us to treats all Media the same way.

In C++, we need to assure that we put the key world `virtual`.

### Etape 6
Shallow copy can cause problem if we modify one of the value.
We use deep copy.