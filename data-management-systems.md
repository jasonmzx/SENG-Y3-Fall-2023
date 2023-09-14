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


#### Distinction made in book: DB Schema vs. DB State

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

![DB-8](./static/DB-8.png)

</details>