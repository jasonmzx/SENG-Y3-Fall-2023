# Data Management Systems ( SOFE3700 )

| Category                 | Mark   |
|--------------------------|--------|
| Quizzes and Assignments  | 10%    |
| Labs                     | 15%    |
| Final Project            | 15%    |
| Midterm (Oct. 6th)       | 20%    |
| Final                    | 40%    |


**Quizzes:**
- Lockdown browser will be used in quizzes and must be done in class.
- Expect a quiz every week. *(I will drop the lowest quiz mark)*

**Midterm:**
- The exam will be on Oct. 6th during the class time.
- No midterm deferral, marks will be added to the final exam

**There will be a group project. (Final Project)**
Team: 4 students
You will be given case studies *(or bring your own project – it
has to be approved by the TA/Professor)* and you need to
apply the design principles and submit a software design
- Report on each phase
- Presentation at the end of the term
- More details will be on Canvas

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 1 | Databases & DB Users</summary>
  
  **Intro:**

  With the boom of Social Media, New types of database systems, often referred to as **big data** storage systems, or **NO-SQL Database Systems** (Google, Amazon, Yahoo)

  Corrolated with **Cloud Storage** aswell.

  We will give an overview of these new types of database systems in Chapter 24.

  **Databases don't only store Text & Numbers!**
  - Multimedia Databases *(Image, Video, Volumetric Files, etc...)*

  - Geographic Information Systems (GISs)

  - Online Analytical Processing (OLAP) *Example a company that makes stock predictions based on Real-time Market Analytics*

  - **Real-time** and **active database technology** is used to control industrial and manufacturing processes.

---

#### Definition: Database management system (DBMS)

- Collection of programs that enables users to create and maintain a database. *(Easier DB Management)*
- DBMS is a general‐purpose software system that facilitates the processes of defining, constructing, manipulating, and sharing databases among various users and applications...
**Examples:**
• MySQL,
• PostgreSQL,
• Microsoft SQL Server,
• Oracle,
• Sybase,
• SAP HANA,
• IBM DB2.

**Main Functions of a DBMS:**

- Defining DBs | Specify data types, structures, constraints of the data to be sorted, titled "meta-data"

- Construction of DBs | Processing of actually storing data on some storage medium controlled by DBMS

- Manipulation of DB | **Retrieval:** query and update the database to reflect the miniworld, and generate reports, **Modification:** Insertions, deletions and updates to its content. The API Layer of a Web Application interfaces with DBMS.

- Sharing of Database to DB Users | Allow multiple users and programs to access the database simultaneously

- System & Security Protection | Preventing crashes & software malfunctions, whilst having Security Safeguards for malicious access.

- Maintain the database system | Allow the system to evolve as requirements change over time



## Application Activities Against a Database (TLDR: GPT is a better prof than the prof)

In a Database Management Systems (DBMS) course, it's crucial to understand the various application activities that interact with a database. These activities are fundamental to the functioning of database systems and play a vital role in data manipulation and retrieval. Below are two key application activities:

### Queries

Queries are a fundamental aspect of interacting with a database. They allow users or applications to access different parts of the data stored in a database and formulate a result for a specific request. Queries can range from simple requests for data retrieval to complex operations that involve multiple database tables. Here's why queries are essential:

- **Data Retrieval:** Queries enable users to fetch specific information from the database, making it possible to obtain the data they need for analysis, reporting, or other purposes.

- **Data Manipulation:** Queries can also be used to modify data in the database. For example, users can update existing records, insert new data, or delete unnecessary information.

- **Data Analysis:** Complex queries can perform calculations, aggregations, and transformations on data, allowing users to derive valuable insights and make informed decisions.

- **Interjoining Tables:** In many cases, queries involve joining multiple database tables to retrieve related information. This interjoining of tables enhances the response to the request by providing a more comprehensive dataset.

### Transactions

Transactions are critical for ensuring data consistency and integrity in a database. They represent a set of operations that are executed as a single unit of work. Transactions can include reading data, updating values, generating new data, and storing it in the database. Here's why transactions are essential:

- **Atomicity:** Transactions are atomic, meaning that they are treated as a single, indivisible unit. This ensures that all the operations within a transaction are either completed successfully or rolled back entirely in case of failure. Atomicity guarantees that the database remains in a consistent state.

- **Consistency:** Transactions help maintain data consistency by enforcing rules and constraints defined in the database schema. If a transaction violates any integrity constraints, it is rolled back, preventing the database from entering an inconsistent state.

- **Isolation:** Transactions run in isolation from each other. This means that the changes made by one transaction are not visible to other transactions until the first transaction is committed. Isolation prevents interference between concurrent transactions.

- **Durability:** Once a transaction is committed, its changes are permanently stored in the database, even in the event of a system failure. This ensures that data remains persistent and can be relied upon.

- It is an executing program or process that includes one or more database accesses (i.e. reading or updating records)

---

#### Example (UNIVERSITY DATABASE) :

![DB-1](./static/DB_1.png)

**Elaboration on "Meta-Data" in the context of DBs**

In the context of databases, **"Meta-Data"** refers to data that provides information about the structure, definition, and organization of the actual data within the database. This includes details about tables, columns, data types, constraints, indexes, and more. Metadata essentially defines how the data is structured and what kind of data it contains.

![DB-2](./static/DB_2.png)


DB Manipulation Example:

Query for All of Student 8's Enrolled Sections

```sql
SELECT Section_identifier FROM Grade_Report WHERE Student_number = 8;
```
I'll be trying to regularly annotate word related db problems into SQL cuz why not


More examples from the book:

![DB-3](./static/DB_3.png)

---

### The Database Approach TL:DR

Here's a concise point-by-point comparison of the traditional file processing approach versus the modern database approach:

**Traditional File Processing: (Legacy)**
- Each user defines and implements separate files for specific software applications. (Reading JSONS for ex.)
- Multiple users maintain their own files and programs for data management.
- Redundant data storage due to each user's separate files. *(5 Million users = 5 Million .dat files in a legacy application)*
- Customized programs for different functions like reporting and data entry.
- Results in wasted storage space and duplicate data maintenance. *(It's messy, it takes up alot of space, issues happen with files laying everywhere)*

**Database Approach:**
- Centralized repository for data.
- Data defined once and accessed by various users.
- Users access data through queries, transactions, and applications.
- Eliminates redundancy in data storage.
- Efficient and consistent data management.

- A multiuser DBMS must allow multiple users to access the database at
the same time
- 
- DBMS must have Concurrency control software to ensure that several users trying to update the same data do so in a controlled manner *Example assigning seats for airline reservation systems*

    - This type of application is called Online transaction processing (OLTP) application
- Ensure that concurrent transactions operate correctly and
efficiently
- This allows hundreds of concurrent transactions to execute per
second.

![DB-4](./static/DB_4.png)


---

### Actors on Scene

![DB-5](./static/DB_5.png)

**Actors on the Scene (Actual Database Users):**
- **Professional Users:** Responsible for database development, design, and application.
- **End Users:** Access and interact with the database for their specific needs.

**Workers Behind the Scene of DBMS (Back-end):**
- **DBMS System Designers:** Develop and implement DBMS modules and interfaces.
- **Tool Developers:** Create software tools for database modeling and performance enhancement.
- **Operators and Maintenance Personnel:** Manage the hardware and software infrastructure for the database system.

</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 2 | Database System Concepts and Architecture</summary>

## 2.1 Data Models, Schemas, and Instances

**Data abstraction** generally refers to the suppression of
details of data organization and storage, and the highlighting of the essential features for an improved understanding of data. 

**A data model** is a collection of concepts that
can be used to describe the structure of a database—provides the necessary means to achieve this abstraction.

Most data models also include a set of **basic operations** for specifying retrievals and updates on the database.

1. Client module
- Run on a user workstation or personal computer.
- Handles user interaction and provides the user-friendly interfaces
such as forms- or menu-based GUIs (graphical user interfaces).
2. Server module,
- Handles data storage, access, search, ...


### Categories of Data Models

- **High-level** or Conceptual data models provide concepts that are close to the way many users perceive data.
  - **Conceptual data models** use concepts such as entities, attributes, and relationships.
  An entity represents a real-world object or concept, such as an employee or a project
  from the miniworld that is described in the database
  - Attribute represents some property of interest that furthert describes the entity. *(Name, age, height, sex)*
  - Relationship  among two or more entities represents an association among the entities, for example, a works-on relationship between a employee and a project.  
  - Chapter 3 presents the entity–relationship model—a popular high-level conceptual data model.

- **Low-level** or Physical data models provide concepts that describe the details of how data is stored on the computer storage media, typically magnetic disks.

- **Representational data models** hide many details of data storage on disk but can be implemented on a computer system directly. *(middle-ground)*

- **Implementation (representational) data models:** Provide concepts that fall between the above two, used by many
commercial DBMS implementations *(e.g. relational data models used in many commercial systems).* Such as the Object Data Model.

- **Self-Describing Data Models:** Combine the description of data with the data values. Examples include XML, key-value stores and some NOSQL systems.

#### Schemas, Instances, and Database State (more vocabulary)
**Database schema**
- Description of a database, database structure, data types, and
constraints
- Specified during database design and is not expected to change
frequently
- The DBMS stores the descriptions of the schema constructs and constraints—also called the meta-data
- **schema evolution** is when the schema updates, and the structure of the tables & DB changes *(example, added D.O.B construct for students)*

**Schema diagram**
- Illustrative display of selected aspects of a database schema *(DBeaver Database - UML View)*

**Schema construct**
- A component of the schema or an object within the schema, e.g., STUDENT, COURSE

![DB-6](./static/DB_6.png)

**NOTE**: A schema diagram displays only some aspects of a schema, such as the names of
record types and data items, and some types of constraints. Other aspects are not
specified in the schema diagram; for example, Figure 2.1 shows neither the data
type of each data item nor the relationships among the various files.


#### Distinction made in book: DB Schema (RED) vs. DB State (GREEN)

Schema is the actual Meta-data telling the DBMS how data is structured within Tables, the current data refers to actual entries

![DB-7](./static/DB_7.png)

*empty state* -> No data
*initial state* -> Data after large load-in or something of this nature
*current state* -> After users do numerous operations on it, the data is at a latest state

The DBMS is also partially responsive for ensure **Valid State**

### Three-Schema Architecture and Data Independence

The goal of the three-schema architecture, illustrated in Figure 2.2, is to separate
the user applications from the physical database. In this architecture, schemas can
be defined at the following three levels:

![DB-8](./static/DB_8.png)

**External Level** includes many External Schemas or User Views. an External Schema describes the part of the DB that the user is interested in, or a JOIN of tables for the user *(External Schema uses representational data model to make it's own schema views)*

**Conceptual Level** refers to the conceptual schema which describes the structure of the whole db, without touching on the physical storage itself. Usually, a **representational data model** is used to describe the conceptual schema when a database system is implemented.

**Internal Level** which refers to the lower-level, closer to the hardware. Describes physical storage structure of DB, describes complete details of data storage, with access `path`s for access to higher level components.

The **three-schema architecture** distinguishes between the user's external view, the database's conceptual design, and the internal storage level in a database system. Although many DBMSs don't strictly separate these levels, they often support this structure, with some even combining the physical and conceptual schemas. Crucially, the three schemas are mere data descriptions, with actual data stored only at the physical level, and transitions between these levels, known as mappings, can be resource-intensive.

---

## Data Independence

**DEFINITION**: The three-schema architecture can be used to further explain the concept of data independence, which can be defined as the capacity to change the schema at one level of a database system without having to change the schema at the next higher level. We got 2 types of data independence:

### **Logical Data Independence** : 
Allows for modifications to the conceptual schema without altering external schemas or application programs. For instance, when expanding or reducing the database, only the view definition and the mappings need adjustment. Even after significant changes, applications referencing the external schema should function as they did before, ensuring stability and flexibility.

Imagine you have a database for a bookstore.  *(GPT EXAMPLE)*

###### Conceptual Schema (Initial):
- **Books**: Title, Author, ISBN, Price, Genre

###### External Schema (User View):
- **User A**: Sees Title, Author, Price
- **User B**: Sees Title, Genre

Now, let's say the bookstore starts storing an additional piece of information: the `Publication Year` of each book.

###### Conceptual Schema (Updated):
- **Books**: Title, Author, ISBN, Price, Genre, Publication Year

Despite this change in the conceptual schema:

- **User A** will still see only the Title, Author, and Price.
- **User B** will still see only the Title and Genre.

The application or interface through which **User A** and **User B** interact with the database remains unchanged, even though the underlying conceptual schema has been modified. This demonstrates _**Logical Data Independence.**_
<br>
<br>

### **Physical Data Independence** 
Is the capacity to change the internal schema without having to change the conceptual schema. Hence, the external schemas need not be changed as well. Changes to the internal schema may be needed because some physical files were reorganized, *for example* by creating additional access structures—to improve the performance of retrieval or update.
 *(GPT EXAMPLE)*
###### Conceptual Schema:
- **Books**: Title, Author, ISBN, Price, Genre

###### Internal Schema (Initial Storage):
- Data is stored in sequential files.
- **Books** are accessed based on their ISBN numbers.

Given the growth of the bookstore, the management decides to enhance data retrieval speed. They introduce an indexing system based on `Genre` for faster searches.

###### Internal Schema (Updated Storage):
- Data still stored in sequential files.
- **Books** can now also be accessed quickly through a `Genre` index.

Despite this change in the internal storage mechanism:

- The conceptual schema remains as **Books**: Title, Author, ISBN, Price, Genre.
- Applications or interfaces querying books by genre *(e.g., "Find all Sci-Fi books")* might see performance improvements, but the query itself remains unchanged.

This example demonstrates how changes to the physical storage level (internal schema) don't impact the higher levels of the database system, showcasing physical data independence.

---

## Database Languages and Interfaces

The DBMS provides appropriate languages and interfaces for each category of users!

**Data Definition Language (DDL)** : Used by the database administrators and designers to define both conceptual and internal schemas.
- The DBMS has a DDL compiler to process DDL statements in order to identify descriptions of the schema constructs and to store the schema description in the DBMS catalog.
- In many DBMSs, the DDL is also used to define internal and external schemas *(user views)*.

In DBMSs where a clear separation is maintained between the conceptual and internal levels, the DDL is used to specify the conceptual schema only. Another language, the **storage definition language (SDL)**, is used to specify the internal schema.

**View Definition Language (VDL)**
- Specifies user views and their mappings to the conceptual schema
- In relational DBMSs, **SQL** is used in the role of DDL, VDL , and DML

**This makes zero fuckn sense, so let's break it down !!!**

---

#### 1. Data Definition Language (DDL)
DDL is used to define and manage the structure of the database.
##### Example:
Imagine you're creating a new bookstore database. You'd use DDL commands to set up the initial structure.

```sql
CREATE TABLE Books (
    BookID INT PRIMARY KEY,
    Title VARCHAR(255),
    Author VARCHAR(255),
    ISBN VARCHAR(13),
    Price DECIMAL(5,2),
    Genre VARCHAR(50)
);
```

#### 2. Storage Definition Language (SDL)
SDL focuses on how data is stored and organized at the physical level.
##### Example:
You might have requirements related to the performance of your bookstore database, like faster data retrieval based on genres. SDL would be used to define the storage and access methods, like specifying a particular type of indexing system or how data blocks are stored on disk. *(Here we're speeding our indexing up with a Binary Tree)*

```sql
DEFINE INDEX GenreIndex ON Books(Genre) USING BTREE;
```

#### 3. View Definition Language (VDL)
VDL is used to define views for particular users or user groups, focusing on the data they can access and the way they see it.
#### Example:
Suppose you want a view for customers that only shows them the **Title**, **Author**, and **Price** of the books, without any internal identifiers like **BookID** or **ISBN**. 

```sql
CREATE VIEW CustomerBookView AS
SELECT Title, Author, Price FROM Books;
```

In the above example, VDL is used to create a view named **CustomerBookView** which displays only selected columns from the Books table.

#### Data Manipulation Language (DML)

DML is responsible for data operations within a database, including:

- **Retrieving** data
- **Inserting** new entries
- **Deleting** existing entries
- **Modifying** data

##### Types of DML

1. **High-level (nonprocedural) DML**
   - Allows concise specification of complex operations.
   - Known as set-at-a-time or set-oriented, meaning it can handle multiple records simultaneously.
   - Example: **SQL**.

2. **Low-level (procedural) DML**
   - Needs to be part of a general programming language like **C++** or **Java**.
   - Operates record-at-a-time, meaning one record is processed at a given moment.
   - Example: **DL/I** commands such as `GET UNIQUE`, `GET NEXT`, etc.

---
### DBMS Interfaces

## Types of Database Interfaces

1. **Menu-based Interfaces for Web Clients/Browsing**
   - Present options through menus, eliminating the need for command memorization.
   - Commonly used: Pull-down menus.
   - Example: A website navigation bar.

2. **Apps for Mobile Devices**
   - Tailored interfaces for mobile users to access data.
   - Example: Banking apps allowing account checks and bill payments.

3. **Forms-based Interfaces**
   - Displays a form for users to input or retrieve data.
   - Designed for naive users for specific transactions.
   - Example: A login form with username and password fields.

4. **Graphical User Interfaces (GUIs)**
   - Show a schema in a diagrammatic form.
   - Users can query by manipulating the diagram.
   - Often use menus and forms.
   - Example: Database visualization tools or ER diagram software.

5. **Natural Language Interfaces**
   - Accepts requests in plain language (e.g., English).
   - Utilizes a dictionary for interpretation.
   - Example: "Find all employees who started after 2020."

6. **Keyword-based Database Search**
   - Similar to web search engines, but for databases.
   - Matches words with documents or records.
   - Example: Searching for a term within a database, like "Python" in a programming tutorial DB.

7. **Speech Input and Output**
   - Allows users to interact with databases using speech.
   - Limited vocabularies but growing in use.
   - Example: Voice assistants checking flight details or credit card balances.

Programmer interfaces:
![DB11](./static/DB_11.png)

---
### The Database System Environment

![DB10](./static/DB_10.png)

Components:
- **The database & DBMS catalog** are usually stored on disk. Access to the disk is controlled primarily by the operating system *(OS)*, which schedules disk read/write.
- **Buffer Management** module to schedule disk read/write, since management of buffer storage has a considerable effect on performance. Reducing disk read/write improves performance considerably.
- **Higher-level stored data manager** module of the DBMS controls access to DBMS information that is stored on disk, whether it is part of the database or the catalog.

_**TOP SECTION OF DIAGRAM**_
It shows interfaces for the DBA Staff, Casual Users, Interactive Users *(Make Queries, Formulate queries aswell)* , App. Programmers who create programs with C++/Java, and parametric users who do data entry work by supplying parameters to predefined transactions.

- DDL Compiler Processes Schema Definitions specified, and stores the **Meta-data** in the DBMS catalog.
- Catalog includes info such as: *Names, Size of Files, Data Types, Data Items, Storage Detail per file, mapping info for schemas, constraints*

# GPT's say on this:

### Key Actors & Components

- **Casual Users**
  - Interaction: Use interactive query interfaces.
  - Tools: Menu-based, form-based, and mobile interactions.

  - **Parametric Users**
  - Interaction: Execute canned transactions using parameters.
  - Example: Supplying parameters like account number for bank transactions.

  - **Application Programmers Users**
  - Languages: Java, C, C++, scripting languages like PHP and Python.
  - Process: Submit code to a precompiler to extract DML commands.

- **Query Compiler**
  - Purpose: Validate and compile queries into an internal form.
  - Operation: Checks syntax, file names, and data elements.

- **Query Optimizer**
  - Purpose: Enhances query performance by optimizing its operations.
  - Consults: System catalog for data statistics.

- **Precompiler**
  - Purpose: Extracts DML commands from host language programs.
  - Result: Object code for database access.

- **Runtime Database Processor**
  - Role: Executes privileged commands, queries, and canned transactions.
  - Interfaces: System catalog, stored data manager, and possibly OS for buffer management.

- **Stored Data Manager**
  - Role: Manages low-level I/O operations between disk and memory.
  
- **Concurrency Control & Backup/Recovery Systems**
  - Purpose: Ensure transaction management, safety, and consistency.

- **DBMS Client Software & Database Server**
  - Structure: Client-server model where the client accesses the DBMS on a separate device.
  - Variations: Clients may also access an intermediate application server.

##### Notes

- The provided architecture isn't specific to one DBMS but represents typical modules.
- The DBMS interfaces with the OS for disk accesses and may control main memory buffering.

---

## Database System Utilites
There are some functions that are provided through additional programs called utilities, it helps the DBMS do specific tasks, thanks to these utils!

#### Database Utilities

- **Loading Utility**
  - Purpose: Used to load existing data files, such as text files or sequential files, into the database. Automates the reformatting of data for storage in the database.
  - Example: Transferring data from one DBMS to another using conversion tools that generate loading programs based on source and target storage descriptions.
  - Some vendors offer conversion tools that generate the appropriate loading programs, given the existing source and target database storage descriptions *(internal schemas)*.

- **Backup Utility**
  - Purpose: Creates backup copies of the database, either as a full dump or using incremental backups to save only changes since the last backup.
  - Example: An incremental backup mechanism that only saves records modified after the last full backup, Incremental Backups conserve storage space. Dumps are quite large *(full-dumps)*

- **Database Storage Reorganization Utility**
  - Purpose: Reorganizes database files into different structures, possibly adding new access paths, to enhance performance.
  - Example: Altering the structure of a product database to add new indexes, optimizing search performance.

- **Performance Monitoring Utility**
  - Purpose: Monitors database usage, collecting statistics for the Database Administrator **(DBA)** to aid in performance-related decisions.
  - Example: Analyzing query performance over time to determine if additional indexes are required or if certain files need reorganization.

Other utilities may be available for sorting files, handling data compression, monitoring access by users, interfacing with the network, and performing other functions.

#### Tools, Application Environments, and Communications Facilities

- **CASE (Computer-Aided Software Engineering) Tools**
  - Purpose: Used during the design phase of database systems.
  - Examples: Rational Rose, TOAD

- **Data Dictionary (Data Repository) System**
  - Purpose: Beyond cataloging, stores design decisions, usage standards, application program descriptions, and user data.
  
- **Application Development Environments**
  - Purpose: Facilitates the construction of database applications, including:
    - Database design
    - GUI development
    - Query and update operations
    - Application program development
  - Examples: PowerBuilder *(Sybase)*, JBuilder *(Borland)*, JDeveloper

- **Communications Software**
  - Purpose: Allows users to connect to databases remotely.

---

## Centralized and Client/Server Architectures for DBMSs

### Centralized DBMSs Architecture

Figure 2.4 illustrates the physical components in a centralized architecture. Gradually, DBMS systems started to exploit the available processing power at the user side, which led to client/server DBMS architectures. *(Better for the DB host, and needed nowadays)*

![DB12](./static/DB_12.png)

Old Computer Systems at Work used to be a bunch of Display Terminals, connected to a central computer, which housed the DBMS itself.
Now everyone uses PC or Mobile Device, so it's different, however the figure shows the O.G style of Display Monitors connecting to the 1 DBMS!

### Basic Client/Server Archs.
The client/server architecture was developed to deal with computing environments in which a large number of PCs, workstations, file servers,
printers, database servers, Web servers, e-mail servers, and other software and equipment are connected via a network.

![DB13](./static/DB_13.png)
![DB14](./static/DB_14.png)

- Has **specialized servers** with specific use-cases / functionalities. for example, here we've got
  - File server: Maintains the files of the client machines.
  - Printer server: Connected to various printers; all print requests by the clients are forwarded to this machine
  - DBMS server
  - Web servers or e-mail servers

- The **client machine**(s) provide the user with the appropriate interfaces to utilize these servers, as well as with local processing power to run local applications. **(Rest API Layer, LAN Network, WiFi Network, etc..)** comms.

### Two-Tier Client/Server Architectures for DBMSs

In the realm of Relational Database Management Systems (RDBMSs), the two-tier architecture represents a clear division between the **client** and the **server**.

#### Key Components:

- **Client Side**:
  - Contains: User interface programs and application programs.
  - Role: Connects to the DBMS server when database access is required.

- **Server Side**:
  - Often termed as: Query server, transaction server, or SQL server.
  - Contains: The functionality related to SQL processing.
  
#### Standard Protocols:

- **Open Database Connectivity (ODBC)**:
  - Role: Serves as an Application Programming Interface (API) for client-side programs to interact with the DBMS.
  - Universality: Works across systems provided both client and server have the necessary software.

- **Java Database Connectivity (JDBC)**:
  - Purpose: Similar to ODBC but designed for the Java programming language.
  - Role: Enables Java client programs to access DBMSs using a standardized interface.

#### Overview:

In this architecture, the client communicates directly with the server. When a client needs data, it establishes a connection to the DBMS on the server side, sends query or transaction requests, processes the received data, and then displays results as necessary. The server, meanwhile, focuses on querying and transactions, keeping the heavy-duty data processing away from the client. 

### N-Tier Architecture

While the two-tier architecture divides the system into client and server, n-tier architectures (like three-tier) involve additional layers, offering more flexibility and scalability.

#### Example: Three-Tier Architecture

1. **Presentation Tier**: User interface (like a web page).
2. **Application Tier**: Logic, processing, or API layer (like a backend API server).
3. **Data Tier**: Database servers, where data is stored and retrieved.

In a three-tier setup, the application tier acts as a mediator, processing client requests before accessing the data tier. It separates the business logic from user interface concerns, leading to more maintainable and scalable systems.

#### Broader Context:

The concept of "n-tier" signifies multiple layers or tiers in the system architecture. Each additional tier allows for further separation of concerns, potentially making systems more modular, scalable, and maintainable. However, each added layer might introduce additional complexity.

![DB15](./static/DB_14.png)

##### Three-Tier Architecture

- **Intermediate Layer**: Often termed as the *application server* or *Web server*, depending on the context.
  
  - **Roles**:
    - Runs application programs.
    - Stores business rules (like procedures or constraints) for data access.
    - Enhances database security by verifying client credentials.
    - Processes client requests and relays database commands/queries to the database server.
    - Transfers (partially) processed data from the database server to the client.

- **Clients**: Include user interfaces and Web browsers.

- **Three Tiers**:
  1. **User Interface**: Interacts with end-users. *(React)*
  2. **Application Rules**: Houses intermediate rules, constraints, and business logic. *(API / SQL Assertions)*
  3. **Data Access**: Manages the retrieval and storage of data. *(JDBC, or DB Connection Library)*

- **Web Integration**: The middle layer can double as a Web server, fetching query results and converting them into dynamic Web pages for client-side Web browsers. The client is typically a PC or a mobile device.

#### N-Tier Architecture

- **Overview**: Splits the system layers further than the three-tier model, resulting in n-tiers where n can be four, five, or more layers.
  
  - **Fine-grained Layers**: Typically, the business logic layer gets subdivided into multiple layers.
  
  - _**Advantages**_:
    - Distributes both programming and data across the network.
    - Each tier can operate on a suitable processor or OS platform.
    - **Offers independence & modularity**: Layers can be managed and scaled separately.

---

## Classification of Database Management Systems (DBMSs)

### 1. Based on Data Model:

- **Relational Data Model**: Widely used in many current commercial DBMSs, known as SQL systems.
- **Object Data Model**: Exists in commercial systems but isn't widespread.
- **NOSQL Systems** (Big Data Systems): Includes various models like:
  - Document-based
  - Graph-based
  - Column-based
  - Key-value data models
- **Legacy Data Models**: Hierarchical and network models.
- **Object-Relational DBMSs**: Combination of object and relational DBMSs.
- **XML-Based DBMSs**: Based on the tree-structured XML model.

### 2. Number of Users:

- **Single-User Systems**: Supports one user at a time, mainly for PCs.
- **Multiuser Systems**: Supports multiple concurrent users.

### 3. Distribution of Database:

- **Centralized DBMS**: Data stored at a single site.
- **Distributed DBMS (DDBMS)**: Database and DBMS software spread over multiple sites linked by a network. Big data systems may have data replicated across hundreds of sites.

---

## Deep Dive: Object-Relational DBMSs

Object-Relational Database Management Systems (ORDBMSs) are a hybrid that aims to combine the best features of both relational and object-oriented databases. They enable users to develop database applications with a more sophisticated data structure compared to relational databases, while still benefiting from relational database features.

### Key Features:

1. **Complex Data Types**: ORDBMSs support complex data and varied data structures like arrays and multimedia formats.
2. **Inheritance**: Just like in object-oriented databases, objects in ORDBMS can inherit properties and methods from other objects.
3. **Object Identity**: Each object in the database has a unique identifier, irrespective of its value.
4. **Encapsulation**: Bundling of data with the methods that operate on that data.
5. **Extended SQL**: ORDBMSs offer extensions to standard SQL to handle object-oriented features.
6. **Relational Capabilities**: Despite the added object features, ORDBMSs still maintain the relational view and capabilities of databases, including ACID properties and SQL querying.

### Advantages:

- **Flexibility**: Easily model real-world entities.
- **Reusable Components**: Code reusability through inheritance.
- **Efficiency**: Handles complex data types more efficiently than RDBMS.

### Disadvantages:

- **Complexity**: Introducing Object Oriented features may increase complexity.
- **Performance**: Due to added features, there might be a performance overhead compared to traditional RDBMSs.

ORDBMSs are suitable for applications where there's a need for complex data modeling, like CAD applications, telecommunication systems, and molecular biology databases.

---

# Slide Questions... TODO !
</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 3 | Data Modeling Using the Entity Relationship (ER) Model</summary>

  
</details>