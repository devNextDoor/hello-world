#Reading data
innov.df<-read.csv(paste("innov1.csv",sep=""))


#Examining dataset
str(innov.df)
nrow(innov.df)


#Eliminating exactly same entries with multiple occurences
innov.df<-unique(innov.df)


#Checking no. of rows in resulting dataset
nrow(innov.df)


#Assigning correct row nos.
rownames(innov.df)<-1:nrow(innov.df)


#Creating and filling column for full names
innov.df$name<-paste(innov.df$fn,innov.df$ln,sep=' ')


#Viewing table after initial changes
View(innov.df)


#Checking for duplicate names, using 'agrep' function and storing intermediate results in table 'p'
p<-data.frame(a=integer(),b=integer())
k<-1
for(i in 1:nrow(innov.df)){
for (j in agrep(innov.df$name[i], innov.df$name,
                ignore.case=TRUE, value=FALSE,
                max.distance = 0.07, useBytes = TRUE)) {
      if(i!=j)
        {
        if((innov.df[i,2]==innov.df[j,2])&&(innov.df[i,3]==innov.df[j,3]))
        {
          p[k,1]<-min(i,j)
          p[k,2]<-max(i,j)
          k<-k+1
        }
      }
}
}
p<-unique(p)


#Eliminating duplicate rows from given data and storing results in 'output.df'
output.df<-innov.df[-p[,1],]
rownames(output.df)<-1:nrow(output.df)


#Examining output table
View(output.df)
nrow(output.df)


#Writing output to CSV file
write.csv(output.df,'output.csv')